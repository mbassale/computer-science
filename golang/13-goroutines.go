package main

import (
	"log"
	"runtime"
	"sync"
)

var wg = sync.WaitGroup{}
var m = sync.RWMutex{}
var counter = 0

func main() {
	log.SetFlags(log.Ldate | log.Ltime | log.Lshortfile)
	log.Printf("Threads: %v\n", runtime.GOMAXPROCS(-1))

	wg.Add(1)
	go sayHello()

	msg := "hello"
	wg.Add(1)
	go func(msg string) {
		log.Println(msg)
		wg.Done()
	}(msg)

	for i := 0; i < 10; i++ {
		wg.Add(2)
		m.RLock()
		go printCounter()
		m.Lock()
		go increment()
	}
	wg.Wait()
	log.Printf("Final Counter: %v\n", counter)
}

func sayHello() {
	log.Println("hello")
	wg.Done()
}

func printCounter() {
	log.Printf("Counter: %v\n", counter)
	m.RUnlock()
	wg.Done()
}

func increment() {
	counter++
	log.Printf("Increment: %v\n", counter)
	m.Unlock()
	wg.Done()
}
