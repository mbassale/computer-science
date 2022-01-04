package main

import (
	"fmt"
)

func main() {
	statePopulationsInMillions := make(map[string]int)
	statePopulationsInMillions = map[string]int{
		"California":   39,
		"Texas":        27,
		"Florida":      20,
		"New York":     19,
		"Pennsylvania": 12,
		"Illinois":     12,
		"Ohio":         11,
	}
	fmt.Println(statePopulationsInMillions)

	// value access
	fmt.Printf("Califonia Population (in millions): %v\n", statePopulationsInMillions["Ohio"])

	// add new value by key
	statePopulationsInMillions["Georgia"] = 10
	fmt.Printf("Georgia Population (in millions): %v\n", statePopulationsInMillions["Georgia"])
	fmt.Println(statePopulationsInMillions)

	// delete a value by key
	delete(statePopulationsInMillions, "Georgia")
	fmt.Println(statePopulationsInMillions)

	// query a non-existent key
	pop, ok := statePopulationsInMillions["Oho"]
	fmt.Printf("Oho Value: %v, Exists: %v\n", pop, ok)

	// length
	fmt.Printf("State Populations: %v\n", len(statePopulationsInMillions))

	// maps works by reference
	sp := statePopulationsInMillions
	delete(sp, "Ohio")
	fmt.Println(sp)
	fmt.Println(statePopulationsInMillions)
}
