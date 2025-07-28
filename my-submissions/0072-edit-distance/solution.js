/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
function solve(s1, s2, i, j, dp) {
    let m = s1.length;
    let n = s2.length;
    if (i == m) {
        return n - j; // insert in s1
    } else if (j == n) {
        return m - i; // delete in s1
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        return (dp[i][j] = solve(s1, s2, i + 1, j + 1, dp));
    } else {
        let insertC = 1 + solve(s1, s2, i, j + 1, dp);

        let deleteC = 1 + solve(s1, s2, i + 1, j, dp);

        let replaceC = 1 + solve(s1, s2, i + 1, j + 1, dp);

        return (dp[i][j] = Math.min(insertC, deleteC, replaceC));
    }
    return -1;
}

var minDistance = function (word1, word2) {
    let m = word1.length;
    let n = word2.length;
    let dp = Array.from({ length: 501 }, () => Array(501).fill(-1));
    return solve(word1, word2, 0, 0, dp);
};

