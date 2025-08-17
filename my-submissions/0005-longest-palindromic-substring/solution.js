/**
 * @param {string} s
 * @return {string}
 */
function solve(s, i, j, dp) {
    if (i >= j) {
        return 1;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) {
        dp[i][j] = solve(s, i + 1, j - 1, dp);
        return dp[i][j];
    }
    return (dp[i][j] = 0);
}

var longestPalindrome = function (s) {
    let n = s.length;
    let dp = Array.from({ length: 1001 }, () => Array(1001).fill(-1));

    let maxLen = -Infinity;
    let sp = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (solve(s, i, j, dp)) {
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }
    }
    return s.substring(sp, sp + maxLen);
};
