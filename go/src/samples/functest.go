package main

import (
	"fmt"
	 "strings")

func main(){
	s1,s2 := convert("sai")
	fmt.Println("name ", s1, " after upper", s2)
}

func convert(name string) (s1,s2 string){
	return name, strings.Title(name)
}
