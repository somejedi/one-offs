package kentreg

import (
	"errors"
	"github.com/PuerkitoBio/goquery"
	"log"
	"net/http"
	"net/http/cookiejar"
	"net/url"
	"strconv"
	"strings"
)

type Class struct {
	Crn        string
	Subject    string
	Course     string
	Section    string
	Campus     string
	Credits    string
	Title      string
	Days       string
	Time       string
	Capacity   string
	Actual     string
	Remaining  string
	Instructor string
	Location   string
}

type Grade struct {
	Crn     string
	Course  string
	Title   string
	Credits string
	Mode    string
	Grade   string
	Status  string
}

type Grades []Grade

type Student struct {
	Client   http.Client
	Username string
	Password string
}

type Info struct {
	Subject string
	Course  string
}

// Log in to kent.edu and save those cookies in client
func (s *Student) Login() {
	jar, _ := cookiejar.New(nil)
	client := http.Client{Jar: jar}
	v := url.Values{}
	v.Set("sid", s.Username)
	v.Add("PIN", s.Password)
	client.PostForm("https://keys.kent.edu/ePROD/twbkwbis.P_ValLogin", v)
	s.Client = client
}

// Search for classes in the Fall 2014 semester
// example subject would be "CHEM"
// course is the course number as a string "12010"
func (s Student) Search(subject string, course string) ([]Class, error) {
	if subject == "" {
		return nil, errors.New("Please enter a subject")
	}
	searchurl := "https://keys.kent.edu/ePROD/bwskfcls.P_GetCrse_Advanced"
	v, _ := url.ParseQuery("rsts=dummy&crn=dummy&term_in=201480&sel_subj=dummy&sel_day=dummy&sel_schd=dummy&sel_insm=dummy&sel_camp=dummy&sel_levl=dummy&sel_sess=dummy&sel_instr=dummy&sel_ptrm=dummy&sel_attr=dummy&sel_subj=PHY&sel_crse=11030&sel_title=&sel_insm=%25&sel_from_cred=&sel_to_cred=&sel_camp=KC&sel_levl=%25&sel_ptrm=%25&sel_instr=%25&sel_sess=%25&sel_attr=%25&begin_hh=0&begin_mi=0&begin_ap=a&end_hh=0&end_mi=0&end_ap=a&SUB_BTN=Class+Search&path=1")
	// must set dummy frist, doesn't work if subject is alone
	v.Set("sel_subj", "dummy")
	v.Add("sel_subj", subject)
	v.Set("sel_crse", course)
	resp, err := s.Client.PostForm(searchurl, v)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	doc, err := goquery.NewDocumentFromResponse(resp)
	if err != nil {
		log.Fatal(err)
	}
	var classes []Class
	doc.Find(".datadisplaytable").Find("tr").Each(func(i int, s *goquery.Selection) {
		var a []string
		s.Find("td").Each(func(i int, s *goquery.Selection) {
			a = append(a, strings.TrimSpace(s.Text()))
		})
		if a != []string(nil) && a[14] != "0" && a[2] != "" {
			var class Class
			class.Crn = a[2]
			class.Subject = a[3]
			class.Course = a[4]
			class.Section = a[5]
			class.Campus = a[6]
			class.Credits = a[7]
			class.Title = a[8]
			class.Days = a[10]
			class.Time = a[11]
			class.Capacity = a[12]
			class.Actual = a[13]
			class.Remaining = a[14]
			class.Instructor = a[21]
			class.Location = a[23]
			classes = append(classes, class)
		}
	})
	return classes, nil
}

// Calls the method Search concurrently
func (s Student) MultiSearch(courses ...Info) []Class {
	messages := make(chan []Class, len(courses))
	for _, i := range courses {
		go func(subject string, course string) {
			classes, _ := s.Search(subject, course)
			messages <- classes
		}(i.Subject, i.Course)
	}
	var clean []Class
	for i := 0; i < len(courses); i++ {
		meh := <-messages
		for _, b := range meh {
			clean = append(clean, b)
		}
	}
	return clean
}

// Semester should either be "fall" or "spring"
// I'll get around to making summer at some point
func (s Student) Grades(semester string, year string) Grades {
	if semester == "" && year == "" {
		log.Fatal(errors.New("Enter semster or year"))
	}
	if semester != "fall" && semester != "spring" {
		log.Fatal(errors.New("semester should be spring or fall"))
	}
	gradeurl := "https://keys.kent.edu/ePROD/bwskogrd.P_ViewGrde_Current"
	v := url.Values{}
	if semester == "fall" {
		v.Set("term_in", year+"80")
	}
	if semester == "spring" {
		v.Set("term_in", year+"10")
	}
	resp, err := s.Client.PostForm(gradeurl, v)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	doc, err := goquery.NewDocumentFromResponse(resp)
	if err != nil {
		log.Fatal(err)
	}
	var grades []Grade
	doc.Find(".datadisplaytable").Find("tbody").Find("tr").Each(func(i int, s *goquery.Selection) {
		var a []string
		s.Find("td").Each(func(i int, m *goquery.Selection) {
			a = append(a, strings.TrimSpace(m.Text()))
		})
		if a[0] != "" {
			var grade Grade
			grade.Crn = a[0]
			grade.Course = a[1]
			grade.Title = a[2]
			grade.Credits = a[3]
			grade.Mode = a[4]
			grade.Grade = a[5]
			grade.Status = a[6]
			grades = append(grades, grade)
		}
	})
	return grades
}

// Sorts through Grades and calculates the Gpa
// Works only on standard grades atm
func (g Grades) GPA() float64 {
	atmCredits := 0.0
	ttlCredits := 0.0
	for _, i := range g {
		if i.Grade != "" || i.Mode != "Standard Letter" {
			credit, _ := strconv.ParseFloat(i.Credits, 64)
			atmCredits += credit
			switch i.Grade {
			case "A":
				ttlCredits += 4.0 * credit
			case "A-":
				ttlCredits += 3.7 * credit
			case "B+":
				ttlCredits += 3.3 * credit
			case "B":
				ttlCredits += 3.0 * credit
			case "B-":
				ttlCredits += 2.7 * credit
			case "C+":
				ttlCredits += 2.3 * credit
			case "C":
				ttlCredits += 2.0 * credit
			case "C-":
				ttlCredits += 1.7 * credit
			case "D+":
				ttlCredits += 1.3 * credit
			case "D":
				ttlCredits += 1.0 * credit
			case "F":
				ttlCredits += 0.0 * credit
			}
		}
	}
	return ttlCredits / atmCredits
}
