package main

import (
	"fmt"
)

var globalA int = 42
var (
	actorName     string = "John Doe"
	companionStar string = "Joan Doe"
	doctorNumber  int    = 13
	season        int    = 10
)

func main() {
	// verbose
	var i int = 42
	fmt.Println(i)
	i = 27
	fmt.Println(i)

	// let compiler to decide
	var j = 42
	fmt.Println(j)

	// concise declaration
	k := 42
	fmt.Println(k)

	var f0 float32 = 42
	fmt.Printf("Val: %v Type: %T\n", f0, f0)

	f0 = float32(i)
	fmt.Printf("Val: %v Type: %T\n", f0, f0)
}
