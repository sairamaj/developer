package main

import (
	"fmt"
	"time"
	"sync"
)

func main(){
	
	// anonymous
	// func() {
	// 	fmt.Println("sleeping...")
	// 	time.Sleep(5 * time.Second)
	// 	fmt.Println("Hello")
	// }()

	// func() {
	// 	fmt.Println("Hi")
	// }()

	var waitGrp sync.WaitGroup
	waitGrp.Add(2)

	go func() {
		defer waitGrp.Done()
		fmt.Println("sleeping...")
		time.Sleep(5 * time.Second)
		fmt.Println("Hello")
	}()

	go func() {
		defer waitGrp.Done()
		fmt.Println("Hi")
	}()

	waitGrp.Wait()
}