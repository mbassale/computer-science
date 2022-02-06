package main

import (
	"errors"
	"net/http"
	"time"
)

type PressureGauge struct {
	ch chan struct{}
}

func NewPressureGauge(limit int) *PressureGauge {
	ch := make(chan struct{}, limit)
	for i := 0; i < limit; i++ {
		ch <- struct{}{}
	}
	return &PressureGauge{
		ch: ch,
	}
}

func (pg *PressureGauge) Process(f func()) error {
	select {
	case <-pg.ch:
		f()
		pg.ch <- struct{}{}
		return nil
	default:
		return errors.New("no more capacity")
	}
}

func doExpensiveProcessing() string {
	time.Sleep(2 * time.Second)
	return "done"
}

const MAX_REQUESTS = 2

func main() {
	pg := NewPressureGauge(MAX_REQUESTS)
	http.HandleFunc("/request", func(w http.ResponseWriter, r *http.Request) {
		err := pg.Process(func() {
			w.Write([]byte(doExpensiveProcessing()))
		})
		if err != nil {
			w.WriteHeader(http.StatusTooManyRequests)
			w.Write([]byte("Too many requests"))
		}
	})
	http.ListenAndServe(":8080", nil)
}
