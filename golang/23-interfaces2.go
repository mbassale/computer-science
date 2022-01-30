package main

type Stringer interface {
	String() string
}

type LogicProvider struct{}

func (lp LogicProvider) Process(data string) string {
	// business logic
	return data
}

type Logic interface {
	Process(data string) string
}

type Client struct {
	L Logic
}

func (c Client) Program() {
	c.L.Process("test data")
}

func main() {
	c := Client{
		L: LogicProvider{},
	}
	c.Program()
}
