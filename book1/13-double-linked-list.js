
class Node {

    data = null;
    next = null;
    prev = null;

    constructor(data, next, prev) {
        this.data = data || null;
        this.next = next || null;
        this.prev = prev || null;
    }
}

class DoubleLinkedList {

    firstNode = null;
    lastNode = null;

    constructor(firstNode, lastNode) {
        this.firstNode = firstNode;
        this.lastNode = lastNode;
    }

    push(value) {
        let newNode = new Node(value);
        if (!this.firstNode) {
            this.firstNode = newNode;
            this.lastNode = newNode;
        } else {
            newNode.prev = this.lastNode;
            this.lastNode.next = newNode;
            this.lastNode = newNode;
        }
    }

    shift() {
        let removedNode = this.firstNode;
        if (removedNode) {
            this.firstNode = this.firstNode.next;
            if (this.firstNode) {
                this.firstNode.prev = null;
            }
            return removedNode.data;
        }
    }
}

