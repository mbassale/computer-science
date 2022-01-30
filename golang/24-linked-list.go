package main

import "fmt"

type LinkedList struct {
	Value interface{}
	Next  *LinkedList
}

func (ll *LinkedList) Insert(pos int, val interface{}) *LinkedList {
	if ll == nil || pos == 0 {
		return &LinkedList{
			Value: val,
			Next:  ll,
		}
	}
	ll.Next = ll.Next.Insert(pos-1, val)
	return ll
}

func main() {
	var linkedList *LinkedList
	for i := 0; i < 10; i++ {
		linkedList = linkedList.Insert(i, i)
	}

	current := linkedList
	for current != nil {
		intVal, ok := current.Value.(int)
		if ok {
			fmt.Printf("Node: %v Value: %d Next: %v\n", current, intVal, current.Next)
		} else {
			fmt.Printf("Node: %v Value: %v Next: %v\n", current, current.Value, current.Next)
		}
		current = current.Next
	}
}
