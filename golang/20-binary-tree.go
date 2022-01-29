package main

import (
	"fmt"
	"math/rand"
	"time"
)

type IntTree struct {
	val         int
	left, right *IntTree
}

func (it *IntTree) Insert(val int) *IntTree {
	if it == nil {
		return &IntTree{val: val}
	}
	if val < it.val {
		it.left = it.left.Insert(val)
	} else if val > it.val {
		it.right = it.right.Insert(val)
	}
	return it
}

func (it *IntTree) Contains(val int) bool {
	switch {
	case it == nil:
		return false
	case val < it.val:
		return it.left.Contains(val)
	case val > it.val:
		return it.right.Contains(val)
	default:
		return true
	}
}

func main() {
	randSource := rand.NewSource(42)
	randGen := rand.New(randSource)

	var it *IntTree
	for i := 0; i < 100; i++ {
		it = it.Insert(randGen.Intn(100))
	}

	var avgDuration float64 = 0
	for i := 0; i < 100; i++ {
		start := time.Now()
		contains := it.Contains(i)
		duration := time.Since(start).Nanoseconds()
		fmt.Printf("Contains(%d): %v %vns\n", i, contains, duration)
		avgDuration += float64(duration)
	}
	fmt.Printf("Avg Contains Time: %vns\n", avgDuration/100)
}
