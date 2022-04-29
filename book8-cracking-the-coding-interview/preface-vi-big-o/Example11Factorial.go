package main

import (
	"fmt"
	"time"
)

func FactorialRecursive(n int) int {
	if n < 0 {
		return -1
	} else if n <= 1 {
		return 1
	} else {
		return n * FactorialRecursive(n-1)
	}
}

func FactorialIterative(n int) int {
	result := 1
	for ; n >= 1; n-- {
		result = result * n
	}
	return result
}

func main() {
	start := time.Now()
	res := FactorialRecursive(10)
	duration := time.Since(start)
	fmt.Printf("FactorialRecursive(10)=%v %vns\n", res, duration.Nanoseconds())
	start = time.Now()
	res = FactorialIterative(10)
	duration = time.Since(start)
	fmt.Printf("FactorialIterative(10)=%v %vns\n", res, duration.Nanoseconds())
}
