package main

import (
	"fmt"
	"reflect"
)

func Reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < len(arr)/2 && j > i; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func ReverseSlice(arr interface{}) {
	size := reflect.ValueOf(arr).Len()
	swap := reflect.Swapper(arr)
	for i, j := 0, size-1; i < size/2 && j > i; i, j = i+1, j-1 {
		swap(i, j)
	}
}

func main() {
	arr0 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	Reverse(arr0)
	fmt.Printf("Array: %v\n", arr0)

	arr1 := make([]int, 0, 10)
	for i := 1; i <= 10; i++ {
		arr1 = append(arr1, i)
	}
	Reverse(arr1)
	fmt.Printf("Array: %v\n", arr1)

	arr2 := []string{"a", "b", "c", "d", "e"}
	ReverseSlice(arr2)
	fmt.Printf("Array: %v\n", arr2)
}
