package main

import (
	"fmt")

func main(){
	val := max(1,5,10,2,100,22)
	fmt.Println("max is:", val)
}

func max(numbers ...int) int {
	max := numbers[0]

	for _, i:= range numbers{
		if( i > max){
			max = i
		}
	}

	return max
}

