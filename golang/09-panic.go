package main

import (
	"log"
)

func main() {
	log.SetFlags(log.Lshortfile)
	log.Println("start")
	panicker()
	log.Println("end")
}

func panicker() {
	log.Println("about to panic")
	defer func() {
		if err := recover(); err != nil {
			log.Println("Error:", err)
			panic(err)
		}
	}()
	panic("something bad happened")
	log.Println("done panicking")
}
