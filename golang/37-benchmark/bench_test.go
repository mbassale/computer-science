package main

import (
	"fmt"
	"testing"
)

var blackhole int

func BenchmarkFileLen(b *testing.B) {
	for _, v := range []int{1, 10, 100, 1000, 10000, 100000} {
		b.Run(fmt.Sprintf("FileLen-%d", v), func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				result, err := FileLen("../data/gutemberg-jungle-book.txt.gz", v)
				if err != nil {
					b.Fatal(err)
				}
				blackhole = result
			}
		})
	}
}

func TestFileLen(t *testing.T) {
	result, err := FileLen("../data/gutemberg-jungle-book.txt.gz", 1)
	if err != nil {
		t.Fatal(err)
	}
	fmt.Println("FileCount:", result)
}
