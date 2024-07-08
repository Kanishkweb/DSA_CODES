/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function (n, k) {
    return recursion(n, k) + 1;
}

// must understand again
function recursion(n, k) {
    if (n === 1) {
        return 0;
    }
    return (recursion(n - 1, k) + k) % n;
}
