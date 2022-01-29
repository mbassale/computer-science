package main

import (
	"fmt"
	"time"
)

type Person struct {
	FirstName string
	LastName  string
	Age       int
}

func (p Person) String() string {
	return fmt.Sprintf("%s %s, age %d", p.FirstName, p.LastName, p.Age)
}

func personExample() {
	p := Person{
		FirstName: "Fred",
		LastName:  "Fredson",
		Age:       52,
	}
	fmt.Println(p.String())
}

type Counter struct {
	total       int
	lastUpdated time.Time
}

func (c *Counter) Increment() {
	c.total++
	c.lastUpdated = time.Now()
}

func (c Counter) String() string {
	if c.lastUpdated.IsZero() {
		return fmt.Sprintf("total: %d, last updated: N/A", c.total)
	}
	return fmt.Sprintf("total: %d, last updated: %v", c.total, c.lastUpdated)
}

func counterExample() {
	var c Counter
	fmt.Println(c.String())
	c.Increment()
	fmt.Println(c.String())
}

type Adder struct {
	start int
}

func (a Adder) AddTo(val int) int {
	return a.start + val
}

func adderExample() {
	adder := Adder{start: 10}
	fmt.Printf("Adder: %v\n", adder.AddTo(5))
	// method closures
	f1 := adder.AddTo
	fmt.Printf("Adder(MethodClosure): %v\n", f1(10))

	// method expression
	f2 := Adder.AddTo
	fmt.Printf("Adder(MethodExpr): %v\n", f2(adder, 15))
}

func main() {
	personExample()
	counterExample()
	adderExample()
}
