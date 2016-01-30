package goplc

import (
	"regexp"
	"net/http"
	"encoding/json"
	"strings"
	"time"
	"io/ioutil"
)

var googletitleapi = regexp.MustCompile("([A-Za-z: ]*)")

type Googlebookapi struct {
	Items []Itemtype
}

type Itemtype struct {
	VolumeInfo VolumeInfotype
}

type VolumeInfotype struct {
	Title string
	Subtitle string
	Authors []string
	Publisher string
	Publisheddate string
	Pagecount int
	Imagelinks Imagelinkstype
	Industryidentifiers []Industryidentifierstype
	Categories []string
	
}

type Imagelinkstype struct {
	Smallthumbnail string
	Thumbnail string
}

type Industryidentifierstype struct {
	Type string
	Identifier string
}

func (u *User) UpdateOverdueWithBooksApi(i int, title string, done chan bool) {

	newtitle := googletitleapi.FindStringSubmatch(title)
	slicetitle := strings.Split(strings.TrimSpace(newtitle[1]), " ")
	strtitle := strings.Join(slicetitle, "+")

	resp, _ := http.Get("https://www.googleapis.com/books/v1/volumes?q=" + strtitle + "&startIndex=0&maxResults=1")

	body, _ := ioutil.ReadAll(resp.Body)

	var bookapi Googlebookapi
	json.Unmarshal(body, &bookapi)

	publishdate, _ := time.Parse("2006-01-02", bookapi.Items[0].VolumeInfo.Publisheddate)

	u.Overdues[i].Oldtitle = u.Overdues[i].Title

	u.Overdues[i].Title = bookapi.Items[0].VolumeInfo.Title
	u.Overdues[i].Subtitle = bookapi.Items[0].VolumeInfo.Subtitle
	u.Overdues[i].Authors = bookapi.Items[0].VolumeInfo.Authors
	u.Overdues[i].Publisheddate = publishdate
	u.Overdues[i].Pagecount = bookapi.Items[0].VolumeInfo.Pagecount
	u.Overdues[i].Categories = bookapi.Items[0].VolumeInfo.Categories
	u.Overdues[i].Thumbnail = bookapi.Items[0].VolumeInfo.Imagelinks.Thumbnail
	u.Overdues[i].Isbn = bookapi.Items[0].VolumeInfo.Industryidentifiers[0].Identifier

	done <- true

}



func (u *User) UpdateHoldsWithBooksApi(i int, title string, done chan bool) {

	newtitle := googletitleapi.FindStringSubmatch(title)
	slicetitle := strings.Split(strings.TrimSpace(newtitle[1]), " ")
	strtitle := strings.Join(slicetitle, "+")

	resp, _ := http.Get("https://www.googleapis.com/books/v1/volumes?q=" + strtitle + "&startIndex=0&maxResults=1")

	body, _ := ioutil.ReadAll(resp.Body)

	var bookapi Googlebookapi
	json.Unmarshal(body, &bookapi)

	publishdate, _ := time.Parse("2006-01-02", bookapi.Items[0].VolumeInfo.Publisheddate)

	u.Holds[i].Oldtitle = u.Holds[i].Title

	u.Holds[i].Title = bookapi.Items[0].VolumeInfo.Title
	u.Holds[i].Subtitle = bookapi.Items[0].VolumeInfo.Subtitle
	u.Holds[i].Authors = bookapi.Items[0].VolumeInfo.Authors
	u.Holds[i].Publisheddate = publishdate
	u.Holds[i].Pagecount = bookapi.Items[0].VolumeInfo.Pagecount
	u.Holds[i].Categories = bookapi.Items[0].VolumeInfo.Categories
	u.Holds[i].Thumbnail = bookapi.Items[0].VolumeInfo.Imagelinks.Thumbnail
	u.Holds[i].Isbn = bookapi.Items[0].VolumeInfo.Industryidentifiers[0].Identifier


	done <- true
}
