package main

import (
	"errors"
	"fmt"
	"time"
)

func timeLimit(workFunc func() (int, error)) (int, error) {
	var result int
	var err error

	done := make(chan struct{})
	go func() {
		result, err = workFunc()
		close(done)
	}()
	select {
	case <-done:
		return result, err
	case <-time.After(2 * time.Second):
		return 0, errors.New("timeout")
	}
}

func main() {
	res, err := timeLimit(func() (int, error) {
		return 1, nil
	})
	fmt.Printf("Res: %v Err: %v\n", res, err)
	res, err = timeLimit(func() (int, error) {
		time.Sleep(3 * time.Second)
		return 1, nil
	})
	fmt.Printf("Res: %v Err: %v\n", res, err)
}
