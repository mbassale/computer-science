package main

import "fmt"

type Employee struct {
	Name string
	ID   string
}

func (e Employee) Description() string {
	return fmt.Sprintf("%s (%s)", e.Name, e.ID)
}

type Manager struct {
	// composition via embedding
	Employee
	Reports []Employee
}

func (m Manager) FindNewEmployee() ([]Employee, bool) {
	if len(m.Reports) == 0 {
		return []Employee{}, false
	}
	return []Employee{m.Reports[len(m.Reports)-1]}, true
}

func employeeExample() {
	m := Manager{
		Employee: Employee{
			Name: "Bob Bobson",
			ID:   "12345",
		},
		Reports: []Employee{},
	}
	fmt.Printf("Manager: Name: %v\n", m.Description())

	newEmployees, ok := m.FindNewEmployee()
	if ok {
		fmt.Println("New Reports:")
		for _, employee := range newEmployees {
			fmt.Println(employee.Description())
		}
	} else {
		fmt.Println("Manager without new reports")
	}
}

type Inner struct {
	X int
}

type Outer struct {
	Inner
	X int
}

func accessingEmbeddedMembers() {
	o := Outer{
		Inner: Inner{
			X: 10,
		},
		X: 20,
	}
	fmt.Printf("OuterX: %v\n", o.X)
	fmt.Printf("InnerX: %v\n", o.Inner.X)
}

func main() {
	employeeExample()
	accessingEmbeddedMembers()
}
