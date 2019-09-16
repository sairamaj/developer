package main

import (
	"fmt"
)

func main() {
	//  declaring slice of string array with 5 as length and cap as 10
	myslice := make([]string,5,10)
	myslice2 := []string {"one", "two", "three","four","five"}
	fmt.Println("slice leng is", len(myslice), "and cap is ", cap(myslice))
	fmt.Println("slice leng is", len(myslice2), "and cap is ", cap(myslice2))

	myslice3 := myslice2[2:5]
	fmt.Println("slice leng is", len(myslice3), "and cap is ", cap(myslice3))
	fmt.Println(myslice3)

}