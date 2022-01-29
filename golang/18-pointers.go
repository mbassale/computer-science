package main

import "fmt"

func main() {
	x := 10
	pointerToX := &x
	fmt.Printf("PtrToX: %v\n", pointerToX)
	fmt.Printf("X: %v\n", *pointerToX)
	z := 5 + *pointerToX
	fmt.Printf("Z: %v\n", z)

	var pointerToY *int
	y := 10
	pointerToY = &y
	fmt.Printf("Y: %v\n", pointerToY)

	x = 10
	failedUpdate(&x)
	fmt.Printf("X: %v\n", x)
	update(&x)
	fmt.Printf("X: %v\n", x)
}

func failedUpdate(px *int) {
	x2 := 20
	px = &x2
}

func update(px *int) {
	*px = 20
}
