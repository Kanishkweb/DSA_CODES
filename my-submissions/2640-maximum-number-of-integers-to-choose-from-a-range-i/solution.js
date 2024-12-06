/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function (banned, n, maxSum) {
    let set = new Set();
    // step 1 is to convert the banned array into the set
    for (let i = 0; i < banned.length; i++) {
        set.add(banned[i]);
    }
    // step 2 iterate over the [1,n] length
    let sum = 0;
    let count = 0;
    for (let i = 1; i <= n; i++) {
        if (set.has(i)) {
            // you have not to take
            continue;
        }
        if (sum + i <= maxSum) {
            sum += i;
            count++;
        } else {
            break;
        }
    }
    return count;
};
