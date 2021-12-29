public class Example9BinaryTreeSum {

    class Node<T extends Number> {
        public Node<T> left;
        public Node<T> right;
        public T value;

        public Node() {
        }

        public Node(T value) {
            this.value = value;
        }

        public Node(Node<T> left, Node<T> right, T value) {
            this.left = left;
            this.right = right;
            this.value = value;
        }
    }

    /**
     * Sum all the nodes in the binary tree.
     * Time: O(n)
     * Memory: O(log(n))
     * 
     * @param <T>
     * @param node
     * @return
     */
    <T extends Number> int sum(Node<T> node) {
        if (node == null)
            return 0;
        return sum(node.left) + node.value.intValue() + sum(node.right);
    }

    void run() {
        var n1 = new Node<Integer>(1);
        var n2 = new Node<Integer>(2);
        var n3 = new Node<Integer>(3);
        var n4 = new Node<Integer>(4);
        var n5 = new Node<Integer>(5);
        n2.left = n1;
        n3.left = n2;
        n3.right = n4;
        n4.right = n5;

        System.out.println("Sum: " + sum(n3));
        System.out.println("SumMath:" + (5 * 6 / 2));
    }

    public static void main(String[] args) {
        new Example9BinaryTreeSum().run();
    }

}
