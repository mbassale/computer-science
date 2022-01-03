package main

import (
	"fmt"
)

func main() {
	const c0 int = 42
	const c1 string = "foo"
	const c2 float32 = 3.14
	fmt.Printf("%v, %T\n", c0, c0)
	fmt.Printf("%v, %T\n", c1, c1)
	fmt.Printf("%v, %T\n", c2, c2)

	const c3 = float32(c0) + float32(len(c1)) + c2
	fmt.Printf("%v, %T\n", c3, c3)

	const (
		a = iota
		b
		c
	)
	fmt.Printf("%v:%T %v:%T %v:%T\n", a, a, b, b, c, c)

	const (
		a2 = iota
	)
	fmt.Printf("%v:%T\n", a2, a2)

	const (
		_ = iota
		readFlag
		writeFlag
		appendFlag
	)
	fmt.Printf("%v:%T %v:%T %v:%T\n", readFlag, readFlag, writeFlag, writeFlag, appendFlag, appendFlag)
	var currentFlag int
	fmt.Printf("%v\n", currentFlag == readFlag)

	const (
		_  = iota
		KB = 1 << (10 * iota)
		MB
		GB
		TB
		PB
		EB
		ZB
		YB
	)

	fileSize := 4000000000.
	fmt.Printf("File size: %.2fGB\n", fileSize/GB)

	const (
		isAdmin = 1 << iota
		isHeadquarters
		canSeeFinancials
		canSeeEMEA
		canSeeNORAM
		canSeeAPAC
	)

	var roles byte = isAdmin | canSeeFinancials | canSeeNORAM
	fmt.Printf("Roles: %b\n", roles)
	fmt.Printf("IsAdmin? %v\n", isAdmin&roles == isAdmin)
	fmt.Printf("CanSeeAPAC? %v\n", canSeeAPAC&roles == canSeeAPAC)
}
