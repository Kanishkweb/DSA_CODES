/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    let totalZeros = 0, zeros = 0, ans = -1, n = s.length;
    for (let c of s) {
        if (c === '0') totalZeros++;
    }
    for (let i = 1; i < n; i++) {
        if (s[i - 1] === '0') {
            zeros++;
            totalZeros--;
        }
        ans = Math.max(ans, zeros + (n - totalZeros - i));
    }
    return ans;
};
