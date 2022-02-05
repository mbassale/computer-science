package main

import (
	"archive/zip"
	"bytes"
	"errors"
	"fmt"
	"os"
	"path"
	"runtime"
)

func printTestCase(testCaseArgs ...interface{}) {
	pc, file, line, ok := runtime.Caller(1)
	if ok {
		funcPtr := runtime.FuncForPC(pc)
		_, file := path.Split(file)
		fmt.Printf("%s:%s():%d: Test Case: ", file, funcPtr.Name(), line)
	} else {
		fmt.Print("Test Case: ")
	}
	for _, val := range testCaseArgs {
		fmt.Printf("%v ", val)
	}
}

func calcRemainderAndMod(numerator, denominator int) (int, int, error) {
	if denominator == 0 {
		return 0, 0, errors.New("denominator is 0")
	}
	return numerator / denominator, numerator % denominator, nil
}

func example1() {
	testCases := [3][2]int{
		{10, 2},
		{10, 0},
		{0, 0},
	}
	for _, testCase := range testCases {
		numerator := testCase[0]
		denominator := testCase[1]
		printTestCase(numerator, denominator)
		res, remainder, err := calcRemainderAndMod(numerator, denominator)
		if err != nil {
			fmt.Printf("Error: %v\n", err)
			continue
		}
		fmt.Printf("%v/%v = %v, %v\n", 10, 2, res, remainder)
	}
}

func doubleEven(i int) (int, error) {
	if i%2 != 0 {
		return 0, fmt.Errorf("%d isn't an even number", i)
	}
	return i * 2, nil
}

func example2() {
	testCases := [3]int{
		0, 1, 2,
	}
	for _, num := range testCases {
		printTestCase(num)
		res, err := doubleEven(num)
		if err != nil {
			fmt.Printf("Error: %v\n", err)
			continue
		}
		fmt.Printf("2*%v = %v\n", num, res)
	}
}

func example3() {
	printTestCase()
	data := []byte("This is not a zip file at all")
	notAZipFile := bytes.NewReader(data)
	_, err := zip.NewReader(notAZipFile, int64(len(data)))
	if err == zip.ErrFormat {
		fmt.Println("Invalid zip file")
		return
	}
	fmt.Println("Valid zip file")
}

type Sentinel string

func (s Sentinel) Error() string {
	return string(s)
}

const (
	ErrID1 = Sentinel("ErrID1")
	ErrID2 = Sentinel("ErrID2")
	ErrID3 = Sentinel("ErrID3")
)

type Status int

const (
	InvalidLogin Status = iota + 1
	NotFound
)

type StatusErr struct {
	Status  Status
	Message string
	Err     error
}

func (se StatusErr) Error() string {
	return se.Message
}

func (se StatusErr) Unwrap() error {
	return se.Err
}

func login(uid, pwd string) error {
	return nil
}

func getData(file string) ([]byte, error) {
	return nil, errors.New("Cannot read data")
}

func LoginAndGetData(uid, pwd, file string) ([]byte, error) {
	err := login(uid, pwd)
	if err != nil {
		return nil, StatusErr{
			Status:  InvalidLogin,
			Message: fmt.Sprintf("invalid credentials for user %s", uid),
			Err:     err,
		}
	}
	data, err := getData(file)
	if err != nil {
		return nil, StatusErr{
			Status:  NotFound,
			Message: fmt.Sprintf("file %s not found", file),
			Err:     err,
		}
	}
	return data, nil
}

func example4() {
	_, err := LoginAndGetData("test", "pwd", "file.txt")
	if err != nil {
		printTestCase()
		fmt.Println(err)
	}
}

func fileChecker(name string) error {
	f, err := os.Open(name)
	if err != nil {
		return fmt.Errorf("in fileChecker: %w", err)
	}
	f.Close()
	return nil
}

func example5() {
	err := fileChecker("not_here.txt")
	if err != nil {
		printTestCase()
		fmt.Println(err)
		if wrappedErr := errors.Unwrap(err); wrappedErr != nil {
			printTestCase()
			fmt.Println(wrappedErr)
		}
		if errors.Is(err, os.ErrNotExist) {
			printTestCase()
			fmt.Println("This file doesn't exist")
		}
	}
}

func main() {
	example1()
	example2()
	example3()
	example4()
	example5()
}
