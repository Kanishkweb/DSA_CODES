/**
 * @param {number[][]} grid
 * @return {number}
 */
function solve(grid, i, j, dp) {
    let m = grid.length;
    let n = grid[0].length;

    if (i >= m) return Infinity;
    if (j >= n) return Infinity;
    if (i == m - 1 && j == n - 1) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    let down = 0;
    down = grid[i][j] + solve(grid, i + 1, j, dp);
    let right = 0;
    right = grid[i][j] + solve(grid, i, j + 1, dp);

    dp[i][j] = Math.min(down, right);
    return dp[i][j];
}

var minPathSum = function (grid) {
    let m = grid.length;
    let n = grid[0].length;
    const dp = Array.from({ length: m }, () => Array(n).fill(-1));
    return solve(grid, 0, 0, dp);
};
