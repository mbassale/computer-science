package main

import (
	"fmt"
	"math"
)

func ifStmts() {
	if true {
		fmt.Println("This test is true")
	} else {
		fmt.Println("This test is false")
	}

	number := 50
	guess := 30
	if guess < 1 || guess > 100 {
		fmt.Println("The guess must be between 1 and 100!")
	} else if guess < number {
		fmt.Println("Too low")
	} else if guess > number {
		fmt.Println("Too high")
	} else if guess == number {
		fmt.Println("You got it!")
	}

	// for floating point representation errors use a delta
	f0 := 0.123
	if math.Abs(f0/math.Pow(math.Sqrt(f0), 2)-1) < 0.0001 {
		fmt.Println("f0 and num are the same")
	} else {
		fmt.Println("f0 and num are different")
	}
}

func switchStmts() {
	// no falling through on go!!!
	switch 1 {
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	default:
		fmt.Println("other")
	}

	// initializer and multiple cases per case
	switch i := 2 + 3; i {
	case 1, 5, 10:
		fmt.Println("one, five or ten")
	case 2, 4, 6:
		fmt.Println("two, four or fix")
	default:
		fmt.Println("other")
	}

	// tagless switch stmt
	i := 10
	switch {
	case i <= 10:
		fmt.Println("less than or equal to ten")
		fallthrough // this is logic-less
	case i <= 20:
		fmt.Println("less than or equal to twenty")
	default:
		fmt.Println("greater than twenty")
	}

	// type switch
	var t0 interface{} = "test"
	switch t0.(type) {
	case int:
		fmt.Println("t0 is an int")
	case float64:
		fmt.Println("t0 is a float64")
	case string:
		fmt.Println("t0 is a string")
		break
		fmt.Println("This will print too")
	case [3]int:
		fmt.Println("t0 is a [3]int")
	default:
		fmt.Println("t0 is another type")
	}
}

func forStmt() {
	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}

	for i, j := 0, 0; i < 5 && j < 5; i, j = i+1, j+2 {
		fmt.Printf("i=%v j=%v\n", i, j)
	}

	k0 := 0
	for ; k0 < 5; k0++ {
		fmt.Printf("k0=%v\n", k0)
	}

	k1 := 0
	for k1 < 5 {
		fmt.Printf("k1=%v\n", k1)
		k1++
	}

	k2 := 0
	for {
		fmt.Printf("k2=%v\n", k2)
		k2++
		if k2 >= 5 {
			break
		}
	}

	// java-style break labels
Loop:
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			fmt.Printf("i=%v j=%v\n", i, j)
			if i == 2 && j == 2 {
				break Loop
			}
		}
	}

	// collections: for range loop
	s := []int{1, 2, 3}
	fmt.Println(s)
	for k, v := range s {
		fmt.Printf("key=%v value=%v\n", k, v)
	}
	for k := range s {
		fmt.Printf("key=%v\n", k)
	}
	for _, v := range s {
		fmt.Printf("value=%v\n", v)
	}
}

func main() {
	ifStmts()
	switchStmts()
	forStmt()
}
