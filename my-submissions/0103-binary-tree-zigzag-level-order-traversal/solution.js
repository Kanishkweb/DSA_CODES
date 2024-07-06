/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */


function createNode(value) {
    return {
        val: value,
        next: null,
    };
}

class MyQueue {
    constructor() {
        this.head = null; // front
        this.tail = null; // back
    }

    enqueue(x) {
        let newNode = createNode(x);
        // add at tail
        if (this.tail == null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    dequeue() {
        if (this.head == null) return;
        let nextNode = this.head.next;
        this.head.next = null;
        this.head = nextNode;
        if (this.head == null) {
            this.tail = null;
        }
    }

    getFront() {
        if (this.head == null) return;
        return this.head.val;
    }

    getBack() {
        if (this.head == null) return;
        return this.tail.val;
    }

    empty() {
        return this.head == null;
    }
}

var zigzagLevelOrder = function (root) {
    if (root == null) return []
    let result = [];
    let arr = [];
    let q = new MyQueue();
    q.enqueue(root);
    q.enqueue(null);
    while (!q.empty()) {
        let front = q.getFront();
        q.dequeue();
        if (front == null) {
            if (result.length % 2 == 0) {
                result.push(arr);
            } else {
                let a = reverse(arr);
                result.push(a);
            }
            arr = [];
            if (q.empty()) break;
            q.enqueue(null);
            continue;
        }
        arr.push(front.val);
        if (front.left) {
            q.enqueue(front.left);
        }
        if (front.right) {
            q.enqueue(front.right);
        }
    }
    return result;
};

function reverse(arr) {
    let temp = [];
    while (arr.length != 0) {
        temp.push(arr.pop());
    }
    return temp;
}
