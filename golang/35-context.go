package main

import (
	"context"
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/http/httptest"
	"os"
	"sync"
	"time"
)

func slowServer() *httptest.Server {
	s := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		time.Sleep(2 * time.Second)
		w.Write([]byte("Slow response"))
	}))
	return s
}

func fastServer() *httptest.Server {
	s := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Query().Get("error") == "true" {
			w.Write([]byte("error"))
			return
		}
		w.Write([]byte("ok"))
	}))
	return s
}

var client = http.Client{}

func callServer(ctx context.Context, label string, url string) error {
	req, err := http.NewRequestWithContext(ctx, http.MethodGet, url, nil)
	if err != nil {
		fmt.Println(label, "request err:", err)
		return err
	}
	resp, err := client.Do(req)
	if err != nil {
		fmt.Println(label, "response err:", err)
		return err
	}
	data, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(label, "read err:", err)
		return err
	}
	result := string(data)
	if result != "" {
		fmt.Println(label, "result:", result)
	}
	if result == "error" {
		fmt.Println("cancelling from", label)
		return errors.New("error happened")
	}
	return nil
}

func callBoth(ctx context.Context, errVal string, slowURL string, fastURL string) {
	ctx, cancel := context.WithCancel(ctx)
	defer cancel()
	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		defer wg.Done()
		err := callServer(ctx, "slow", slowURL)
		if err != nil {
			cancel()
		}
	}()
	go func() {
		defer wg.Done()
		err := callServer(ctx, "fast", fastURL+"?error="+errVal)
		if err != nil {
			cancel()
		}
	}()
	wg.Wait()
	fmt.Println("done with both")
}

func main() {
	ss := slowServer()
	defer ss.Close()
	fs := fastServer()
	defer fs.Close()

	ctx := context.Background()
	callBoth(ctx, os.Args[1], ss.URL, fs.URL)
}
