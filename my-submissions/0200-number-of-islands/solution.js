/**
 * @param {character[][]} grid
 * @return {number}
 */

function dfs(grid, i, j) {
    let m = grid.length;
    let n = grid[0].length;
    if (i < 0 || i >= m || j >= n || j < 0) {
        return;
    }

    if (grid[i][j] != "1") {
        return;
    }
    grid[i][j] = "2";

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

var numIslands = function (grid) {
    let m = grid.length;
    let n = grid[0].length;
    let island = 0;  // count of no of Island;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] == "1") {
                dfs(grid, i, j);
                island += 1;
            }
        }
    }
    return island;
};
