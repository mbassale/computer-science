
class Node {
    constructor(value, next = null) {
        this.value = value;
        this.next = next;
    }
}

function insertNode(head, newValue) {
    
    // one node list
    if (head.next == head) {
        const newNode = new Node(newValue);
        newNode.next = head;
        head.next = newNode;   
        if (newValue < head.value) {
            head = newNode;
        }
        return head;
    }

    let previousNode = null;
    let node = head;
    do {
        if (node.value > newValue) {
            break;
        }
        previousNode = node;
        node = node.next;
    } while (node != head);

    const newNode = new Node(newValue);
    if (previousNode) {
        previousNode.next = newNode;
    }
    newNode.next = node;

    return head;
}

function arrayToList(arr) {
    let head = null;
    let lastNode = null;
    for (const num of arr) {
        const node = new Node(num);
        if (head === null) {
            head = node;
        }
        if (lastNode) {
            lastNode.next = node;
        }
        lastNode = node;
    }
    if (lastNode) {
        lastNode.next = head;
    }
    return head;
}

function listToArray(head) {
    const arr = [];
    let node = head;
    do {
        arr.push(node.value);
        node = node.next;
    } while (node != head);
    return arr;
}

const tests = [
    { list: [1], newValue: 0, expected: [0, 1] },
    { list: [1], newValue: 2, expected: [1, 2] },
    { list: [1, 3, 4, 7, 9, 10], newValue: 6, expected: [1, 3, 4, 6, 7, 9, 10] },
    { list: [-10, -5, 9, 20, 50, 90], newValue: 1, expected: [-10, -5, 1, 9, 20, 50, 90] }
];

for (const test of tests) {
    const head = arrayToList(test.list);
    const head2 = insertNode(head, test.newValue);
    const result = listToArray(head2);
    console.log('list:', test.list, 'newValue:', test.newValue, 'expected:', test.expected, 'result:', result);
}