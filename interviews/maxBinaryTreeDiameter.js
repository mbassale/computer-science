class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class DiameterInfo {
    constructor(diameter, depth) {
        this.diameter = diameter;
        this.depth = depth;
    }
}

function traverse(node) {
    // base case
    if (!node) {
        return new DiameterInfo(0, 0);
    }

    const leftDiameterInfo = traverse(node.left);
    const rightDiameterInfo = traverse(node.right);

    const currentMaxDiameter = Math.max(leftDiameterInfo.diameter, rightDiameterInfo.diameter);
    const maxPathDepth = leftDiameterInfo.depth + rightDiameterInfo.depth;
    const newDiameter = Math.max(maxPathDepth, currentMaxDiameter);
    const newDepth = 1 + Math.max(leftDiameterInfo.depth, rightDiameterInfo.depth);
    return new DiameterInfo(newDiameter, newDepth);
}

function maxBinaryTreeDiameter(rootNode) {
    return traverse(rootNode).diameter;
}

function findNode(rootNode, value) {
    const queue = [rootNode];
    while (queue.length > 0) {
        const currentNode = queue.shift();
        if (currentNode.value === value) {
            return currentNode;
        }
        currentNode.left && queue.unshift(currentNode.left);
        currentNode.right && queue.unshift(currentNode.right);
    }
    return null;
} 

function buildTree(nodes) {
    const rootNode = new Node(nodes[0].value);
    for (const node of nodes) {
        let currentNode = findNode(rootNode, node.value);
        if (!currentNode) continue;
        if (node.left) {
            let leftNode = findNode(rootNode, node.left);
            if (!leftNode) {
                leftNode = new Node(node.left);
            }
            currentNode.left = leftNode;
        }
        if (node.right) {
            let rightNode = findNode(rootNode, node.right);
            if (!rightNode) {
                rightNode = new Node(node.right);
            }
            currentNode.right = rightNode;
        }
    }
    return rootNode;
}

function printTree(rootNode) {
    const queue = [rootNode];
    while (queue.length > 0) {
        const currentNode = queue.shift();
        if (!currentNode) continue;
        console.log('node:', currentNode);
        if (currentNode.left) {
            queue.unshift(currentNode.left);
        }
        if (currentNode.right) {
            queue.unshift(currentNode.right);
        }
    }
}

const tests =  [
    {
        tree: [
            {value: 1, left: 3, right: 2},
            {value: 2, left: null, right: null},
            {value: 3, left: 7, right: 4},
            {value: 7, left: 8, right: null},
            {value: 4, left: null, right: 5},
            {value: 8, left: 9, right: null},
            {value: 5, left: 6, right: null},
            {value: 9, left: null, right: null},
            {value: 6, left: null, right: null}
        ],
        expected: 6
    },
    {
        tree: [
            {value: 1, left: 3, right: 11},
            {value: 3, left: 4, right: 10},
            {value: 11, left: null, right: 12},
            {value: 10, left: null, right: null},
            {value: 4, left: 6, right: null},
            {value: 12, left: null, right: null},
            {value: 6, left: null, right: 7},
            {value: 7, left: null, right: 9},
            {value: 9, left: null, right: null}
        ],
        expected: 7
    }
];

for (const test of tests) {
    const rootNode = buildTree(test.tree);
    //printTree(rootNode);
    const result = maxBinaryTreeDiameter(rootNode);
    console.log('tree:', test.tree, 'expected:', test.expected, 'result:', result);
}