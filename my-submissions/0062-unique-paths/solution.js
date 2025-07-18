/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
function solve(m, n, grid, i, j, dp) {
    // base case
    if (grid[m - 1][n - 1] == 1) {
        grid[m - 1][n - 1] = 0;
        return 1;
    }
    if (i >= m || j >= n) {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (grid[i][j] == 0) grid[i][j] = 1;
    let right = solve(m, n, grid, i, j + 1, dp);
    let down = solve(m, n, grid, i + 1, j, dp);
    grid[i][j] = 0;
    dp[i][j] = right + down;
    return dp[i][j];
}

var uniquePaths = function (m, n) {
    let grid = Array.from({ length: m }, () => Array(n).fill(0));
    let dp = Array.from({ length: m }, () => Array(n).fill(-1));
    // the robot is here on grid[0][0]
    grid[0][0] = 1;

    return solve(m, n, grid, 0, 0, dp);
};
