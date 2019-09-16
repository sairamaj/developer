package main

import (
	"fmt"
)

func main(){

	// for {
	// 	fmt.Println("infinite loop")
	// }

	for i:=0 ; i<10; i++ {
		fmt.Println("i is ", i)
	}

	items := []string{"one", "two", "three"}

	for i:= range items {
		fmt.Println("this is index ",i)
	}

	for _, i:= range items {
		fmt.Println("this is value ",i)
	}
}

