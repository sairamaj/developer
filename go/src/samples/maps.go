package main

import (
	"fmt"
)

func main() {

	titles := make(map[string]int)

	titles["one"] = 1
	titles["two"] = 2
	fmt.Println(titles)

	titles2 := map[string]int{
		"three" : 3,
		"four" : 4,
	}

	fmt.Println(titles2)

	for key,val := range titles {
		fmt.Println("key ", key, "value ", val)
	}

	delete(titles, "one")		// removing item

	for key,val := range titles {
		fmt.Println("key ", key, "value ", val)
	}
}