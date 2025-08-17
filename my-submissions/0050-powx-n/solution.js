/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
function solve(x, n) {
    // base case
    if (n == 0) return 1;

    // if n is even
    if (n % 2 == 0) {
        let half = solve(x, n / 2);
        return half * half;
    }

    // if n is odd
    return x * solve(x, n - 1);
}

var myPow = function (x, n) {
    if (n < 0) {
        return 1 / solve(x, -n);
    }
    return solve(x, n);
};
