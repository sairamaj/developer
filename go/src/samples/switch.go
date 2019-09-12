package main

import (
	"fmt"
)

func main() {
	switch "docker" {
	case "linux":
		fmt.Println("linux") // implicit break
	case "docker":
		fmt.Println("docker")
		fallthrough // it goes to next also
	default:
		fmt.Println("something else")
	}

	// multiple in one case.
	switch 1 {
	case 0, 1, 2:
		fmt.Println("multi")
	}
}
