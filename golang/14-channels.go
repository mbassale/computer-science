package main

import (
	"fmt"
	"time"
)

var doneCh = make(chan struct{})

func main() {
	ch := make(chan int)
	go func(ch <-chan int) {
		for {
			select {
			case i := <-ch:
				fmt.Println(i)
			case <-doneCh:
				break
			}
		}
	}(ch)
	for j := 0; j < 5; j++ {
		go func(ch chan<- int) {
			ch <- 42
			ch <- 27
		}(ch)
	}
	time.Sleep(100 * time.Millisecond)
	doneCh <- struct{}{}
	close(ch)
}
