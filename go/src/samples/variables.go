package main

import (
	"fmt"
	"reflect"
)

// var(
// 	name, course string
// 	module float64
// )

// package level
var (
	name   = "sai"
	course = "test"
	module = "3.2"
)

func main() {
	a := 10                       // declare and assign
	a = 11                        // assign
	const speedOfLightMph = 18600 // const , defined and assigned
	// b := 11		// this is error as we are not using it
	fmt.Println("Name is ", name, "and of type ", reflect.TypeOf(name))
	fmt.Println("Module is ", module, "and of type ", reflect.TypeOf(module))
	fmt.Println("A is ", a, reflect.TypeOf(a))
}
