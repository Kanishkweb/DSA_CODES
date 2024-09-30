class CustomStack {
    constructor(maxSize) {
        this.stack = new Array(maxSize).fill(0);
        this.top = -1;
    }

    push(x) {
        if (this.top < this.stack.length - 1) {
            this.top++;
            this.stack[this.top] = x;
        }
    }

    pop() {
        if (this.top !== -1) {
            return this.stack[this.top--];
        }
        return -1;
    }

    increment(k, val) {
        for (let i = 0; i < Math.min(k, this.top + 1); i++) {
            this.stack[i] += val;
        }
    }
}
