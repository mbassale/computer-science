package main

import "fmt"

func IsPrime(n int) bool {
	for x := 2; x*x <= n; x++ {
		if n%x == 0 {
			return false
		}
	}
	return true
}

func main() {
	for n := 0; n <= 100; n++ {
		fmt.Printf("IsPrime %v? %v\n", n, IsPrime(n))
	}
}
