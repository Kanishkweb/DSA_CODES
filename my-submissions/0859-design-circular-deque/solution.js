class MyCircularDeque {
    constructor(k) {
        this.dq = [];
        this.n = k;
    }

    insertFront(value) {
        if (this.dq.length < this.n) {
            this.dq.unshift(value);
            return true;
        }
        return false;
    }

    insertLast(value) {
        if (this.dq.length < this.n) {
            this.dq.push(value);
            return true;
        }
        return false;
    }

    deleteFront() {
        if (this.dq.length > 0) {
            this.dq.shift();
            return true;
        }
        return false;
    }

    deleteLast() {
        if (this.dq.length > 0) {
            this.dq.pop();
            return true;
        }
        return false;
    }

    getFront() {
        return this.dq.length > 0 ? this.dq[0] : -1;
    }

    getRear() {
        return this.dq.length > 0 ? this.dq[this.dq.length - 1] : -1;
    }

    isEmpty() {
        return this.dq.length === 0;
    }

    isFull() {
        return this.dq.length === this.n;
    }
}
