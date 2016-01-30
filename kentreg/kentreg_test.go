package kentreg

import (
	"github.com/kr/pretty"
	"os"
	"testing"
)

var username = os.Getenv("USERNAME")
var password = os.Getenv("PASSWORD")

func TestMultiSearch(t *testing.T) {
	me := Student{Username: username, Password: password}
	if me.Password == "" {
		t.Error("please enter password")
	}
	me.Login()
	bleh := me.MultiSearch(Info{"CHEM", "10062"}, Info{"ENG", "21011"}, Info{"CHEM", "10060"}, Info{"MATH", "12001"}, Info{"SOC", "12050"})
	pretty.Print("length of multisearch ")
	pretty.Println(len(bleh))
}

func TestSearch(t *testing.T) {
	me := Student{Username: username, Password: password}
	if me.Password == "" {
		t.Error("please enter password")
	}
	me.Login()
	bleh, _ := me.Search("PHY", "11030")
	pretty.Print("len of search ")
	pretty.Println(len(bleh))
}

func TestGrade(t *testing.T) {
	me := Student{Username: username, Password: password}
	if me.Password == "" {
		t.Error("please enter password")
	}
	me.Login()
	pretty.Print("len of grades ")
	grades := me.Grades("spring", "2014")
	pretty.Println(len(grades))
	pretty.Printf("GPA %f\n", grades.GPA())
}
