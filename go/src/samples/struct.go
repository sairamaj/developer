package main

import (
	"fmt"
)

func main(){
	type Person struct {
		Name string
		Age int
	}

	var p Person
	p1 := new(Person)
	p2 := Person {
		Name : "sai",
		Age : 53,
	}

	fmt.Println(p)
	fmt.Println(p1)
	fmt.Println(p2)
}