package main

import (
	"fmt"
	"time"
)

func example1() {
	a := []int{2, 4, 6, 8, 10}
	ch := make(chan int, len(a))
	for _, v := range a {
		go func(val int) {
			ch <- val * 2
		}(v)
	}
	for i := 0; i < len(a); i++ {
		fmt.Println(<-ch)
	}
}

func countTo(max int) <-chan int {
	ch := make(chan int)
	go func() {
		for i := 0; i < max; i++ {
			ch <- i
		}
		close(ch)
	}()
	return ch
}

func example2() {
	for i := range countTo(10) {
		fmt.Println(i)
	}
}

// Tries 3 search functions, returns the result of the fastest one.
func searchData(s string, searchers []func(string) []string) []string {
	done := make(chan struct{})
	result := make(chan []string)
	for _, searcher := range searchers {
		go func(searcher func(string) []string) {
			select {
			case result <- searcher(s):
			case <-done:
			}
		}(searcher)
	}
	r := <-result
	close(done)
	return r
}

func example3() {
	result := searchData("test data", []func(string) []string{
		func(string) []string {
			fmt.Println("Function1")
			time.Sleep(time.Second * 1)
			return []string{"Function1"}
		},
		func(string) []string {
			fmt.Println("Function2")
			time.Sleep(time.Second * 2)
			return []string{"Function2"}
		},
		func(string) []string {
			fmt.Println("Function3")
			return []string{"Function3"}
		},
	})
	fmt.Printf("Result: %v\n", result)
}

func countTo2(max int) (<-chan int, func()) {
	ch := make(chan int)
	done := make(chan struct{})
	cancel := func() {
		close(done)
	}
	go func() {
		for i := 0; i < max; i++ {
			select {
			case <-done:
				return
			case ch <- i:
			}
		}
	}()
	return ch, cancel
}

func example4() {
	ch, cancel := countTo2(10)
	for i := range ch {
		if i > 5 {
			break
		}
		fmt.Println(i)
	}
	cancel()
}

func processForExample5(num int) int {
	return num * 2
}

func processChannel(ch chan int) []int {

	const conc = 10
	results := make(chan int, conc)
	for i := 0; i < conc; i++ {
		go func() {
			v := <-ch
			results <- processForExample5(v)
		}()
	}
	var out []int
	for i := 0; i < conc; i++ {
		out = append(out, <-results)
	}
	return out
}

func main() {
	example1()
	example2()
	example3()
	example4()
}
