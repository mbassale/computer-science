class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def sum(self) -> int:
        """
        Calculates the sum of all nodes in the binary tree.
        Time: O(n)
        Memory: O(log(n))
        """
        return self._sum(self)

    def _sum(self, node=None):
        if node is None:
            return 0
        return self._sum(node.left) + node.value + self._sum(node.right)


def run():
    nodes = [Node(1), Node(2), Node(3), Node(4), Node(5)]
    nodes[2].left = nodes[1]
    nodes[2].right = nodes[3]
    nodes[1].left = nodes[0]
    nodes[3].right = nodes[4]
    print('Sum:', nodes[2].sum())


if __name__ == '__main__':
    run()
