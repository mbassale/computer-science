package main

import (
	"fmt"
	"os"
	"testing"
	"time"
)

var testTime time.Time

func TestMain(m *testing.M) {
	fmt.Println("Set up stuff for tests here")
	testTime = time.Now()
	exitVal := m.Run()
	fmt.Println("Clean up stuff after tests here")
	os.Exit(exitVal)
}

func Test_addNumbers(t *testing.T) {
	fmt.Println("TestTime: ", testTime)
	result := addNumbers(2, 3)
	if result != 5 {
		t.Errorf("incorrect result: expected %d, got %d", 5, result)
	}
}
