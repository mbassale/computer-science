
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

    dump() {
        console.log(this.root);
        }
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
