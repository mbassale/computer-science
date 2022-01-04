package main

import "fmt"

type Node struct {
	Left  *Node
	Right *Node
	Value int
}

func binaryTreeSum(node *Node) int {
	if node == nil {
		return 0
	}
	return binaryTreeSum(node.Left) + node.Value + binaryTreeSum(node.Right)
}

func main() {
	root := Node{
		Left: &Node{
			Left: &Node{
				Value: 1,
			},
			Value: 2,
		},
		Right: &Node{
			Right: &Node{
				Value: 5,
			},
			Value: 4,
		},
		Value: 3,
	}
	sum := binaryTreeSum(&root)
	fmt.Printf("Sum: %v\n", sum)
}
