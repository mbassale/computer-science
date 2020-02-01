
class TreeNode {
    value = null;
    left = null;
    right = null;

    constructor(value, left, right) {
        this.value = value || null;
        this.left = left || null;
        this.right = right || null;
    }
}

class BinaryTree {

    root = null;

    constructor(root) {
        this.root = root || null;
    }

    search (value) {
        let searchImpl = (value, node) => {
            if (!node || node.value === value) {
                return node;
            } else if (value < node.value) {
                return searchImpl(value, node.left);
            } else {
                return searchImpl(value, node.right);
            }
        };
        return searchImpl(value, this.root);
    }

    insert(value) {
        let insertImpl = (value, node) => {
            if (value < node.value) {
                if (!node.left) {
                    node.left = new TreeNode(value);
                } else {
                    insertImpl(value, node.left);
                }
            } else if (value > node.value) {
                if (!node.right) {
                    node.right = new TreeNode(value);
                } else {
                    insertImpl(value, node.right);
                }
            }
        };
        insertImpl(value, this.root);
    }

    remove(value) {

        const lift = (node, nodeToDelete) => {
            if (node.left) {
                node.left = lift(node.left, nodeToDelete);
                return node;
            }
            nodeToDelete.value = node.value;
            return node.right;
        };

        const removeImpl = (val, node) => {
            if (!node) return null;
            if (val < node.value) {
                node.left = removeImpl(val, node.left);
                return node;
            }
            if (val > node.value) {
                node.right = removeImpl(val, node.right);
                return node;
            }
            if (val == node.value) {
                if (!node.left) return node.right;
                if (!node.right) return node.left;
                node.right = lift(node.right, node);
                return node;
            }
        };
        removeImpl(value, this.root);
    }

    traverse(node = null) {
        const n = node || this.root;
        if (n.left) this.traverse(n.left);
        console.log(n.value);
        if (n.right) this.traverse(n.right);
    }

    dump() {
        console.log(this.root);
    }

}

let node1 = new TreeNode(1);
let node2 = new TreeNode(10);
let root = new TreeNode(5, node1, node2);
let binaryTree = new BinaryTree(root);
binaryTree.dump();
console.log('search(1) = ', binaryTree.search(1));
console.log('insert(6)');
binaryTree.insert(6);
binaryTree.dump();
console.log('search(6) = ', binaryTree.search(6));
binaryTree.traverse();
binaryTree.remove(6);
binaryTree.dump();
binaryTree.traverse();
