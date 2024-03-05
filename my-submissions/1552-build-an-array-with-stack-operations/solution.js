/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function (target, n) {
    let stack = [];
    let operations = [];
    let j = 0;
    // loop the should go to the steam of the no
    for (i = 1; i <= n; i++) {
        stack.push(i);
        operations.push("Push")
        let topOfStack = stack.length - 1
        if (target[j] != stack[topOfStack]) {
            stack.pop()
            operations.push("Pop")
            j--
        }
        if (j > n || JSON.stringify(target) == JSON.stringify(stack)) {
            break;
        }
        j++
    }
    return operations;
};
