package main

import (
	"fmt"
	"log"
)

type greeter struct {
	greeting string
	name     string
}

func (g greeter) greet() {
	log.Println(g.greeting, g.name)
}

type counter int

func (n *counter) inc() *counter {
	*n += 1
	return n
}

func main() {
	log.SetFlags(log.Lshortfile | log.Ldate | log.Ltime)
	sayMessage("Hello Go!", 10)
	greeting := "Hello"
	name := "Stacey"
	sayGreeting(&greeting, &name)
	log.Printf("Name: %s", name)
	int_sum := sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
	log.Println("The sum is", int_sum)

	int_sum2 := sum2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
	log.Println("The sum is", *int_sum2)

	int_sum3 := sum3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
	log.Println("The sum is", int_sum3)

	d, err := divide(5.0, 0.0)
	if err != nil {
		log.Println(err)
	}
	log.Println("Division:", d)

	func0 := func() {
		log.Println("Anonymous func")
	}
	log.Printf("Anonymous func addr: %p\n", func0)
	func0()

	var divide func(float64, float64) (float64, error)
	divide = func(a, b float64) (float64, error) {
		return 0.0, nil
	}
	divide(5.0, 0)

	g := greeter{
		greeting: "Hello",
		name:     "Go",
	}
	g.greet()

	var idx counter
	idx.inc().inc().inc().inc().inc()
	log.Printf("Counter Value: %v\n", idx)
}

func sayMessage(msg string, idx int) {
	log.Println(msg)
	log.Println("The value of the index is", idx)
}

func sayGreeting(greeting, name *string) {
	log.Println(*greeting, *name)
	*name = "Ted"
}

func sum(values ...int) int {
	log.Println(values)
	result := 0
	for _, v := range values {
		result += v
	}
	return result
}

func sum2(values ...int) *int {
	result := 0
	for _, v := range values {
		result += v
	}
	return &result
}

func sum3(values ...int) (result int) {
	for _, v := range values {
		result += v

	}
	return
}

func divide(a, b float64) (float64, error) {
	if b == 0.0 {
		return 0.0, fmt.Errorf("Cannot divide by zero")
	}
	return a / b, nil
}
