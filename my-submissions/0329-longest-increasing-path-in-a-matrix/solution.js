/**
 * @param {number[][]} matrix
 * @return {number}
 */
function solve(matrix, i, j, dp) {
    let m = matrix.length;
    let n = matrix[0].length;

    if (i >= m || j >= n) {
        return 1;
    }
    if (dp[i][j] != -1) return dp[i][j];
    // all the directions it will go also we will iterate in loop to solve all the possible path;

    // .......................................
    let left = 0;
    if (j < n - 1) {
        if (matrix[i][j + 1] > matrix[i][j]) {
            left = 1 + solve(matrix, i, j + 1, dp);
        }
    }
    let down = 0;
    if (i < m - 1) {
        if (matrix[i + 1][j] > matrix[i][j]) {
            down = 1 + solve(matrix, i + 1, j, dp);
        }
    }
    let right = 0;
    if (j > 0) {
        if (matrix[i][j - 1] > matrix[i][j]) {
            right = 1 + solve(matrix, i, j - 1, dp);
        }
    }
    let up = 0;
    if (i > 0) {
        if (matrix[i - 1][j] > matrix[i][j]) {
            up = 1 + solve(matrix, i - 1, j, dp);
        }
    }
    dp[i][j] = Math.max(left, right, down, up);
    return dp[i][j];
}

var longestIncreasingPath = function (matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    let dp = Array.from({ length: m }, () => Array(n).fill(-1));
    let result = 0;
    for (let k = 0; k < m; k++) {
        for (let l = 0; l < n; l++) {
            let start = matrix[k][l];
            let go = solve(matrix, k, l, dp);
            result = Math.max(result, go);
        }
    }
    return result + 1;
};
