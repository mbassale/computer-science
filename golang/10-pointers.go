package main

import (
	"log"
)

func pointers1() {
	var a int = 42
	var b *int = &a
	log.Println("&a:", &a, "a:", a, "b:", b, "*b:", *b)
	*b = 27
	log.Println("&a:", &a, "a:", a, "b:", b, "*b:", *b)
}

func pointers2() {
	a := [3]int{1, 2, 3}
	b := &a[0]
	c := &a[1]
	log.Printf("%v %p %p\n", a, b, c)
}

type DummyStruct struct {
	foo int
	bar string
}

func pointers3() {
	var s0 *DummyStruct
	s0 = &DummyStruct{foo: 42}
	log.Println(s0)

	var s1 *DummyStruct
	log.Println(s1)
	s1 = new(DummyStruct)
	log.Println(s1)
	s1.foo = 42
	s1.bar = "its the answer"
	log.Println(s1)
}

func main() {
	log.SetFlags(log.Lshortfile)
	pointers1()
	pointers2()
	pointers3()
}
