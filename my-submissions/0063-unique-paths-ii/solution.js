/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */

function solve(m, n, grid, i, j, dp) {
    // base case
    if (grid[m - 1][n - 1] == 2) {
        grid[m - 1][n - 1] = 0;
        return 1;
    }
    if (i >= m || j >= n) {
        return 0;
    }
    // for obstacle
    if (grid[i][j] == 1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (grid[i][j] == 0) grid[i][j] = 2;
    let right = solve(m, n, grid, i, j + 1, dp);
    let down = solve(m, n, grid, i + 1, j, dp);
    grid[i][j] = 0;
    dp[i][j] = right + down;
    return dp[i][j];
}

var uniquePathsWithObstacles = function (obstacleGrid) {
    let m = obstacleGrid.length;
    let n = obstacleGrid[0].length;
    let dp = Array.from({ length: m }, () => Array(n).fill(-1));

    return solve(m, n, obstacleGrid, 0, 0, dp);
};
