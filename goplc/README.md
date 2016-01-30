goplc
=====

Go client for acessing the Portage Library Consortium website.

Works with Kent Free Library, Portage County District Library, Reed Memorial Library

This is a work in progress. It takes ~3 seconds to pull in all info, but thanks to the Google Books API you get access to a lot more info on the books listed in your account.


# Example #

	package main
	
	import "github.com/somejedi/goplc"
	import "fmt"

	func main() {
		me, err := goplc.Client("CARD NUMBER", "PIN NUMBER")
		if err != nil {
			panic(err)
		}
		
		me.GetHolds()
		me.GetOverdue()
		
		fmt.Println(me.Holdstext)
		fmt.Println(me.Overduetext)
		
		fmt.Println("Number of Holds => ", len(me.Holds))
		fmt.Println("Number of Overdue items => ", len(me.Holds))

		if me.Holds[0].Title != "" {
			fmt.Println("First Held Item")
			fmt.Println("\tTitle => " + me.Holds[0].Title)
			fmt.Println("\tStatus => " + me.Holds[0].Status)
		}
	}

	Output:
 
	3 requests (holds). 3 ready for pickup.
	$9.80 in unpaid fines and bills
	Number of Holds =>  3
	Number of Overdue items =>  3
	First Held Item
		Title => Einstein
		Status => Ready. Must pick up by 06-09-13


sweet.
