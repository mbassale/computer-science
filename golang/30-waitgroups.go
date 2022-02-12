package main

import (
	"fmt"
	"sync"
	"time"
)

func example1() {
	var wg sync.WaitGroup
	wg.Add(3)
	go func() {
		defer wg.Done()
		sleepTime := 3 * time.Second
		fmt.Printf("Sleeping #1: %v ..\n", sleepTime)
		time.Sleep(sleepTime)
		fmt.Println("Done #1.")
	}()
	go func() {
		defer wg.Done()
		sleepTime := 2 * time.Second
		fmt.Printf("Sleeping #2: %v ..\n", sleepTime)
		time.Sleep(sleepTime)
		fmt.Println("Done #2.")
	}()
	go func() {
		defer wg.Done()
		sleepTime := 1 * time.Second
		fmt.Printf("Sleeping #3: %v ..\n", sleepTime)
		time.Sleep(sleepTime)
		fmt.Println("Done #3.")
	}()
	wg.Wait()
}

func processAndGather(in <-chan int, processor func(int) int, num int) []int {
	out := make(chan int, num)
	var wg sync.WaitGroup
	wg.Add(num)
	for i := 0; i < num; i++ {
		go func() {
			defer wg.Done()
			for v := range in {
				out <- processor(v)
			}
		}()
	}
	go func() {
		wg.Wait()
		close(out)
	}()
	var result []int
	for v := range out {
		result = append(result, v)
	}
	return result
}

func main() {
	example1()
}
