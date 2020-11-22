
class Node {
    constructor(value, next = null) {
        this.value = value;
        this.next = next;
    }
}

function mergeLinkedLists(headOne, headTwo) {
    let p1 = headOne;
    let p1Prev = null;
    let p2 = headTwo;
    while (p1 && p2) {
        if (p1.value < p2.value) {
            p1Prev = p1;
            p1 = p1.next;
        } else {
            if (p1Prev) {
                p1Prev.next = p2;
            }
            p1Prev = p2;
            p2 = p2.next;
            p1Prev.next = p1;
        }
    }
    if (!p1) {
        p1Prev.next = p2;
    }
    return headOne.value < headTwo.value ? headOne : headTwo;
}

function array2List(array) {
    const head = new Node(array[0]);
    let previous = head;
    for (let i = 1; i < array.length; i++) {
        const node = new Node(array[i]);
        previous.next = node;
        previous = node;
    }
    return head;
}

function list2Array(head) {
    let node = head;
    let values = [];
    while (node) {
        values.push(node.value);
        node = node.next;
    }
    return values;
}

const tests = [
    { list1: [2, 6, 7, 8], list2: [1, 3, 4, 5, 9, 10], expected: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]},
    { list1: [0, 1, 2, 3, 4, 5, 7, 8, 9, 10], list2: [6], expected: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]}
];

for (const test of tests) {
    const headOne = array2List(test.list1);
    const headTwo = array2List(test.list2);
    const result = mergeLinkedLists(headOne, headTwo);
    console.log('list1:', list2Array(headOne), 'list2:', list2Array(headTwo), 'expected:', test.expected, 'result:', list2Array(result));
}