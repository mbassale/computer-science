package main

import (
	"fmt"
)

func main() {
	s0 := "this is a string"
	fmt.Printf("%v, %T\n", s0[2], s0[2])

	s1 := "this is also a string"
	s2 := s0 + " " + s1
	fmt.Printf("%v, %T\n", s2, s2)

	b0 := []byte(s2)
	fmt.Printf("%v, %T\n", b0, b0)

	r0 := 'a'
	fmt.Printf("%v, %T\n", r0, r0)

	var r1 rune = 'b'
	fmt.Printf("%v, %T\n", r1, r1)
}
