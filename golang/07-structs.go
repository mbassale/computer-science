package main

import (
	"fmt"
	"reflect"
)

type Doctor struct {
	id        int
	name      string
	specialty string
}

type Animal struct {
	// tags
	Name   string `required:"true" max:"100"`
	Origin string
}

type Bird struct {
	// embed the Animal struct into the Bird struct
	Animal
	SpeedKPH float32
	CanFly   bool
}

func main() {
	// struct initialization
	doctor0 := Doctor{
		id:        1,
		name:      "John Doe",
		specialty: "General (Adults)",
	}
	fmt.Printf("Doctor: %v\n", doctor0)
	fmt.Printf("Doctor Name: %v\n", doctor0.name)

	// anonymous struct
	doctor1 := struct{ name string }{name: "Joan Doe"}
	doctor2 := doctor1
	doctor2.name = "Tom Baker"
	doctor3 := &doctor1
	fmt.Println(doctor1)
	fmt.Println(doctor2)
	fmt.Println(doctor3)

	// embedding
	animal0 := Bird{}
	animal0.Name = "Emu"
	animal0.Origin = "Australia"
	animal0.SpeedKPH = 48
	animal0.CanFly = false
	fmt.Println(animal0)

	animal1 := Bird{
		Animal:   Animal{Name: "Emu", Origin: "Australia"},
		SpeedKPH: 48,
		CanFly:   false,
	}
	fmt.Println(animal1)

	// tags
	t := reflect.TypeOf(Animal{})
	field, _ := t.FieldByName("Name")
	fmt.Println(field.Tag)
	fmt.Printf("IsRequired? %v Max: %v\n", field.Tag.Get("required"), field.Tag.Get("max"))
}
