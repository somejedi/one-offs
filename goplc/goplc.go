package goplc

import (
	"net/http/cookiejar"
	"net/http"
	"net/url"
	"io/ioutil"
	"fmt"
	"regexp"
	"strings"
	"time"
)

const kentfreelibraryUrl = "https://webpac.portagecounty.lib.oh.us"

var holdsregexp = regexp.MustCompile("href=\"(.*/holds)\" target=\"_self\">(.*)</a>")
var holdurltitleregexp = regexp.MustCompile("for=\"canceli.*\"><a href=\"(.*)\">(.*)</a></label>")
var holdstatusregexp = regexp.MustCompile("<td  class=\"patFuncStatus\">(.*)</td>")
var holdpickupregexp = regexp.MustCompile("<td class=\"patFuncPickup\">(.*)</td>")

var overdueregexp = regexp.MustCompile("href=\"(.*/overdues)\" target=\"_self\">(.*)</a>")
var overduetitleregexp = regexp.MustCompile("class=\"patFuncFinesEntryTitle\"><br /><em>(.*)</em></td>")
var overdueamtregexp = regexp.MustCompile("class=\"patFuncFinesDetailAmt\">(.*)</td>")
var overduestatusregexp = regexp.MustCompile("class=\"patFuncFinesDetailType\">(.*)</td>")



type User struct {
	Id string
	Pin string
	Client http.Client
	Holdsurl string
	Holdstext string
	Overdueurl string
	Overduetext string
	Holds []Hold
	Overdues []Overdue
}

type Hold struct {
	Title string
	Subtitle string
	Authors []string
	Publisheddate time.Time
	Pagecount int
	Categories []string
	Thumbnail string
	Isbn string
	Oldtitle string
	Url string
	Status string
	Pickup string
}

type Overdue struct {
	Title string
	Subtitle string
	Authors []string
	Publisheddate time.Time
	Pagecount int
	Categories []string
	Thumbnail string
	Isbn string
	Oldtitle string
	Amount string
	Status string
}

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func Client(id string, pin string) (*User, error) {
	user := &User{}

	if id != "" && pin != "" {
		user.Id = id
		user.Pin = pin
	} else {
		return user, fmt.Errorf("Please enter id and pin")
	}

	jar, err := cookiejar.New(nil)
	check(err)
	user.Client = http.Client{Jar: jar}

	resp, err := user.Client.PostForm(kentfreelibraryUrl + "/patroninfo~S10/", url.Values{"code": {user.Id}, "pin": {user.Pin}, "pat_submit": {"xxx"}} )
	check(err)
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)
	check(err)

	holds := holdsregexp.FindStringSubmatch(string(body))
	overdue := overdueregexp.FindStringSubmatch(string(body))

	if len(holds) > 1 {
		user.Holdsurl = holds[1]
		user.Holdstext = holds[2]
	}

	if len(overdue) > 1 {
		user.Overdueurl = overdue[1]
		user.Overduetext = overdue[2]
	}

	return user, nil

}

func (u *User) GetHolds() {

	resp, err := u.Client.Get(kentfreelibraryUrl + u.Holdsurl)
	check(err)

	body, err := ioutil.ReadAll(resp.Body)
	check(err)

	urltitle := holdurltitleregexp.FindAllStringSubmatch(string(body), -1)
	status := holdstatusregexp.FindAllStringSubmatch(string(body), -1)
	pickup := holdpickupregexp.FindAllStringSubmatch(string(body), -1)

	var msg []bool
	done := make(chan bool)

	for i := 0; i < len(urltitle); i++ {
		u.Holds = append(u.Holds, Hold{Title: strings.TrimSpace(urltitle[i][2]), 
								Url: strings.TrimSpace(urltitle[i][1]), 
								Status: strings.TrimSpace(status[i][1]), 
								Pickup: strings.TrimSpace(pickup[i][1]),
							})
		go u.UpdateHoldsWithBooksApi(i, strings.TrimSpace(urltitle[i][2]), done)
	}

	for len(msg) < len(u.Holds) {
		msg = append(msg, <-done)
	}

}

func (u *User) GetOverdue() {
	resp, err := u.Client.Get(kentfreelibraryUrl + u.Overdueurl)
	check(err)

	body, err := ioutil.ReadAll(resp.Body)
	check(err)

	title := overduetitleregexp.FindAllStringSubmatch(string(body), -1)
	amount := overdueamtregexp.FindAllStringSubmatch(string(body), -1)
	status := overduestatusregexp.FindAllStringSubmatch(string(body), -1)

	var msg []bool
	done := make(chan bool)


	for i := 0; i < len(title); i++ {
		u.Overdues = append(u.Overdues, Overdue{Title: strings.TrimSpace(title[i][1]), 
											Amount: strings.TrimSpace(amount[i][1]), 
											Status: strings.TrimSpace(status[i][1]),
										})
		go u.UpdateOverdueWithBooksApi(i, strings.TrimSpace(title[i][1]), done)
	}

	for len(msg) < len(title) {
		msg = append(msg, <-done)
	}
}






















