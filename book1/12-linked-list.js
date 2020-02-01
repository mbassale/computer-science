
class Node {
    constructor(data, nextNode) {
        this.data = data || null;
        this.nextNode = nextNode || null;
    }
}

class LinkedList {
    constructor(firstNode) {
        this.firstNode = firstNode || null;
    }

    read(index) {
        let currentNode = this.firstNode;
        let currentIndex = 0;

        while (currentNode && currentIndex < index) {
            currentNode = currentNode.nextNode;
            currentIndex++;
        }

        return currentNode ? currentNode.data : null;
    }

    indexOf(value) {
        let currentNode = this.firstNode;
        let currentIndex = 0;
        while (currentNode) {
            if (currentNode.data === value) {
                return currentIndex;
            }
            currentNode = currentNode.nextNode;
            currentIndex++;
        }
        return null;
    }

    insert(index, value) {
        let newNode = new Node(value);

        if (index === 0) {
            newNode.nextNode = this.firstNode;
            this.firstNode = newNode;
        } else {
            let currentNode = this.firstNode;
            let currentIndex = 0;
            while (currentIndex < (index - 1)) {
                currentNode = currentNode.nextNode;
                currentIndex++;
            }
            newNode.nextNode = currentNode.nextNode;
            currentNode.nextNode = newNode;
        }

        return this;
    }

    delete(index) {
        if (index === 0) {
            this.firstNode = this.firstNode.nextNode;
        } else {
            let currentNode = this.firstNode;
            let currentIndex = 0;

            while (currentIndex < (index - 1)) {
                currentNode = currentNode.nextNode;
                currentIndex++;
            }

            currentNode.nextNode = currentNode.nextNode.nextNode;
        }

        return this;
    }

    print() {
        let currentNode = this.firstNode;
        while (currentNode) {
            console.log(currentNode.data);
            currentNode = currentNode.nextNode;
        }
    }
}

let node = new Node('once');
let node2 = new Node('upon');
let node3 = new Node('a');
let node4 = new Node('time');
node.nextNode = node2;
node2.nextNode = node3;
node3.nextNode = node4;

let list = new LinkedList(node);
console.log('read(3) = ' + list.read(3));
console.log('indexOf(time) = ' + list.indexOf('time'));
list.insert(4, 'on');
console.log('index(4) = ' + list.read(4));
list.delete(4);
list.print();