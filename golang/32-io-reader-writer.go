package main

import (
	"compress/gzip"
	"fmt"
	"io"
	"os"
	"strings"
)

func countLetters(r io.Reader) (map[string]int, error) {
	buf := make([]byte, 2048)
	out := map[string]int{}
	for {
		n, err := r.Read(buf)
		for _, b := range buf[:n] {
			if (b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z') {
				out[string(b)]++
			}
		}
		if err == io.EOF {
			return out, nil
		}
		if err != nil {
			return nil, err
		}
	}
}

func example1() {
	s := "The quick brown fox jumped over the lazy dog"
	sr := strings.NewReader(s)
	counts, err := countLetters(sr)
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
	fmt.Printf("LetterCounts: %v\n", counts)
}

func buildGZipReader(fileName string) (*gzip.Reader, func(), error) {
	r, err := os.Open(fileName)
	if err != nil {
		return nil, nil, err
	}
	gr, err := gzip.NewReader(r)
	if err != nil {
		return nil, nil, err
	}
	return gr, func() {
		gr.Close()
		r.Close()
	}, nil
}

func example2() {
	r, closer, err := buildGZipReader("data/gutemberg-jungle-book.txt.gz")
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
	defer closer()
	counts, err := countLetters(r)
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	}
	fmt.Printf("Jungle's Book Letter Count: %v\n", counts)
}

func main() {
	example1()
	example2()
}
