package main

import (
	"bytes"
	"fmt"
	"io"
)

func main() {
	var w Writer = ConsoleWriter{}
	w.Write([]byte("Hello Go!"))

	int_counter := IntCounter(0)
	var inc Incrementer = &int_counter
	for i := 0; i < 10; i++ {
		fmt.Println(inc.Increment())
	}

	var wc WriterCloser = NewBufferedWriterCloser()
	wc.Write([]byte("Hello Listeners, this is a test"))
	wc.Close()

	// downcasting
	bwc := wc.(*BufferedWriterCloser)
	fmt.Println(bwc)

	r, ok := wc.(io.Reader)
	if ok {
		fmt.Println(r)
	} else {
		fmt.Println("Conversion failed")
	}

	// empty interface, void* reference
	var wc2 interface{} = NewBufferedWriterCloser()
	if wc2, ok := wc2.(io.WriteCloser); ok {
		wc2.Write([]byte("Hello, this is a test"))
		wc2.Close()
	}

	// type reflection using switch
	var i interface{} = 0
	switch i.(type) {
	case int:
		fmt.Println("i is an integer")
	case string:
		fmt.Println("i is a string")
	default:
		fmt.Println("I don't know what i is")
	}
}

type Incrementer interface {
	Increment() int
}

type IntCounter int

func (ic *IntCounter) Increment() int {
	*ic++
	return int(*ic)
}

type Writer interface {
	Write([]byte) (int, error)
}

type Closer interface {
	Close() error
}

type WriterCloser interface {
	Writer
	Closer
}

type BufferedWriterCloser struct {
	buffer *bytes.Buffer
}

type ConsoleWriter struct {
}

func (cw ConsoleWriter) Write(data []byte) (int, error) {
	n, err := fmt.Println(string(data))
	return n, err
}

func (bwc *BufferedWriterCloser) Write(data []byte) (int, error) {
	n, err := bwc.buffer.Write(data)
	if err != nil {
		return 0, err
	}
	v := make([]byte, 8)
	for bwc.buffer.Len() > 8 {
		_, err := bwc.buffer.Read(v)
		if err != nil {
			return 0, err
		}
		_, err = fmt.Println(string(v))
		if err != nil {
			return 0, err
		}
	}
	return n, nil
}

func (bwc *BufferedWriterCloser) Close() error {
	for bwc.buffer.Len() > 0 {
		data := bwc.buffer.Next(8)
		_, err := fmt.Println(string(data))
		if err != nil {
			return err
		}
	}
	return nil
}

func NewBufferedWriterCloser() *BufferedWriterCloser {
	return &BufferedWriterCloser{
		buffer: bytes.NewBuffer([]byte{}),
	}
}
