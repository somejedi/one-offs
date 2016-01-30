kentreg
==========

A go client for Kent State's class lookup.

```go
package main

import "github.com/somejedi/kentreg"
import "github.com/kr/pretty"

func main() {
	me := kentreg.Student{Username:"BLEH", Password:"BLAH"}
	me.Login()
	pretty.Println(me.Search("PHY", "11030"))
	pretty.Println(me.Grades("fall", "2014"))
}

[]kentreg.Class{
    {Crn:"17345", Subject:"PHY", Course:"11030", Section:"003", Campus:"KC", Credits:"3.000", Title:"SEVEN IDEAS THAT SHOOK THE UNIVERSE", Days:"MWF", Time:"11:00 am-11:50 am", Capacity:"130", Actual:"35", Remaining:"95", Instructor:"John M.  Barrick (P)", Location:"SMH 00108"},
    {Crn:"17346", Subject:"PHY", Course:"11030", Section:"004", Campus:"KC", Credits:"3.000", Title:"SEVEN IDEAS THAT SHOOK THE UNIVERSE", Days:"MWF", Time:"01:10 pm-02:00 pm", Capacity:"200", Actual:"21", Remaining:"179", Instructor:"John M.  Barrick (P)", Location:"SMH 00108"}
}

[]kentreg.Grade{
	{Crn:"10729", Course:"ARTH-12001-001", Title:"ART AS A WORLD PHENOMENON", Credits:"3",Mode:"Standard Letter", Grade:"A-", Status:"Unofficial"},
	{Crn:"16216", Course:"PHIL-11001-001", Title:"INTRODUCTION TO PHILOSOPHY", Credits:"3", Mode:"Standard Letter", Grade:"C+", Status:"Unofficial"}
}
```
