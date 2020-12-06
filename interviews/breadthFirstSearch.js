
class Node {
    constructor(value, children = []) {
        this.value = value;
        this.children = children || [];
    }
}

function breadthFirstSearch(root) {
    const nodeLabels = [];
    const queue = [root];
    while (queue.length > 0) {
        const node = queue.shift();
        nodeLabels.push(node.value);
        for (const child of node.children) {
            queue.push(child);
        }
    }
    return nodeLabels;
}

function findNode(root, value) {
    if (root.value == value) {
        return root;
    }
    for (const childNode of root.children) {
        const node = findNode(childNode, value);
        if (node) {
            return node;
        }
    }
    return null;
}

function buildGraph(spec) {
    let root = new Node(spec[0].value);
    for (const nodeSpec of spec) {
        let node = findNode(root, nodeSpec.value);
        for (const childValue of nodeSpec.children) {
            let childNode = findNode(root, childValue);
            if (!childNode) {
                childNode = new Node(childValue);
            }
            node.children.push(childNode);
        }
    }
    return root;
}

function checkResult(expected, result) {
    if (expected.length === result.length) {
        for (let i = 0; i < expected.length; i++) {
            if (expected[i] !== result[i]) return false;
        }
        return true;
    }
    return false;
}

const tests = [
    { graph: [
        { value: 'A', children: ['B', 'C', 'D'] },
        { value: 'B', children: ['E', 'F'] },
        { value: 'C', children: [] },
        { value: 'D', children: ['G', 'H'] },
        { value: 'E', children: [] },
        { value: 'F', children: ['I', 'J'] },
        { value: 'G', children: ['K'] },
        { value: 'H', children: [] },
        { value: 'I', children: [] },
        { value: 'J', children: [] },
        { value: 'K', children: [] }
    ], expected: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'] }
];

for (const test of tests) {
    const graph = buildGraph(test.graph);
    const result = breadthFirstSearch(graph);
    console.log('graph:', test.graph, 'expected:', test.expected, 'result:', result, 'ok:', checkResult(test.expected, result));
}