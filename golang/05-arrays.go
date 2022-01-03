package main

import (
	"fmt"
)

func main() {
	grades0 := [3]int{97, 85, 93}
	fmt.Printf("Grades: %v\n", grades0)

	grades1 := [...]int{97, 85, 93}
	fmt.Printf("Grades: %v\n", grades1)

	var students [3]string
	students[0] = "Lisa"
	students[1] = "Ahmed"
	students[2] = "Arnold"
	fmt.Printf("Students: %v\n", students)
	fmt.Printf("Student #1: %v\n", students[1])
	fmt.Printf("Number of Students: %v\n", len(students))

	var identityMatrix [3][3]int = [3][3]int{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	}
	fmt.Printf("I=%v\n", identityMatrix)

	a := [...]int{1, 2, 3}
	b := &a
	b[1] = 5
	fmt.Printf("%v, %T\n", a, a)
	fmt.Printf("%v, %T\n", b, b)

	// creating slices
	s0 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	s1 := s0[:]
	s2 := s0[3:]
	fmt.Printf("%v, %T\n", s0, s0)
	fmt.Printf("Length: %v\n", len(s0))
	fmt.Printf("Capacity: %v\n", cap(s0))
	fmt.Printf("%v, %T Length: %v Capacity: %v\n", s1, s1, len(s1), cap(s1))
	fmt.Printf("%v, %T Length: %v Capacity: %v\n", s2, s2, len(s2), cap(s2))

	// preallocating capacity
	s3 := make([]int, 3, 100)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s3, len(s3), cap(s3))

	// checking how backing array is resized
	s4 := []int{}
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 1)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 2)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 3)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 4)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 5)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	s4 = append(s4, 6, 7, 8, 9)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))
	// append elements using slice destructuring
	s4 = append(s4, []int{10, 11, 12, 13, 14, 15, 16, 17}...)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s4, len(s4), cap(s4))

	// dequeue
	s5 := s4[1:]
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s5, len(s5), cap(s5))
	// enqueue
	s5 = append(s5, 18)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s5, len(s5), cap(s5))
	// pop
	s6 := s4[:len(s4)-1]
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s6, len(s6), cap(s6))
	// push
	s6 = append(s6, 18)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s6, len(s6), cap(s6))

	// remove in the middle
	s7 := append(a[:2], a[3:]...)
	fmt.Printf("Val: %v Len: %v Cap: %v\n", s7, len(s7), cap(s7))
}
