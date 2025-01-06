/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function(boxes) {
    const n = boxes.length;
    const prefix = Array(n).fill(0);
    const postfix = Array(n).fill(0);
    let pre = 0, post = 0, now = 0;

    // Prefix array
    for (let i = 0; i < n; i++) {
        now += pre;
        prefix[i] = now;
        if (boxes[i] === '1') pre++;
    }

    now = 0;
    // Postfix array
    for (let i = n - 1; i >= 0; i--) {
        now += post;
        postfix[i] = now;
        if (boxes[i] === '1') post++;
    }

    // Combine prefix and postfix
    const result = Array(n);
    for (let i = 0; i < n; i++) {
        result[i] = prefix[i] + postfix[i];
    }
    return result;
};
