package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
	"time"
)

type Item struct {
	ID   string `json:"id"`
	Name string `json:"name"`
}

type Order struct {
	ID          string    `json:"id"`
	DateOrdered time.Time `json:"date_ordered"`
	CustomerID  string    `json:"customer_id"`
	Items       []Item    `json:"items"`
}

func example1() {
	order := Order{
		ID:          "1",
		DateOrdered: time.Now(),
		CustomerID:  "1",
		Items: []Item{
			{ID: "1", Name: "Item1"},
			{ID: "2", Name: "Item2"},
			{ID: "3", Name: "Item3"},
		},
	}
	orderJson, err := json.Marshal(order)
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
	fmt.Printf("Order: %v\n", string(orderJson))

	var order2 Order
	err = json.Unmarshal([]byte(orderJson), &order2)
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
	fmt.Printf("Order: %v\n", order2)
}

type Person struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func example2() {
	toFile := Person{
		Name: "John Doe",
		Age:  40,
	}
	tmpFile, err := ioutil.TempFile(os.TempDir(), "sample-")
	if err != nil {
		panic(err)
	}
	defer os.Remove(tmpFile.Name())
	err = json.NewEncoder(tmpFile).Encode(toFile)
	if err != nil {
		panic(err)
	}
	err = tmpFile.Close()
	if err != nil {
		panic(err)
	}
	tmpFile2, err := os.Open(tmpFile.Name())
	if err != nil {
		panic(err)
	}
	var personFromFile Person
	err = json.NewDecoder(tmpFile2).Decode(&personFromFile)
	if err != nil {
		panic(err)
	}
	err = tmpFile2.Close()
	if err != nil {
		panic(err)
	}
	fmt.Printf("Person: %v\n", personFromFile)
}

func example3() {
	var person Person
	personJsonData := "{\"name\": \"Fred\", \"age\": 40}{\"name\": \"Mary\", \"age\": 21}{\"name\": \"Pat\", \"age\": 30}"
	dec := json.NewDecoder(strings.NewReader(personJsonData))
	for dec.More() {
		err := dec.Decode(&person)
		if err != nil {
			panic(err)
		}
		fmt.Printf("Person: %v\n", person)
	}
}

func main() {
	example1()
	example2()
	example3()
}
