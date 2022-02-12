package main

import (
	"fmt"
	"sync"
)

type Parser interface {
	Parse(string) string
}

type SimpleParser struct {
}

func (p SimpleParser) Parse(data string) string {
	return "parsing: " + data
}

var parser Parser
var once sync.Once

func Parse(dataToParse string) string {
	once.Do(func() {
		parser = initParser()
	})
	return parser.Parse(dataToParse)
}

func initParser() Parser {
	fmt.Println("Running initParser()")
	return SimpleParser{}
}

func main() {
	fmt.Println(Parse("hello parser world!"))
	fmt.Println(Parse("hello parser world! #2"))
}
