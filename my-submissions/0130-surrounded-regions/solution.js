/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
function dfs(board, adj, i, j) {
    let m = board.length;
    let n = board[0].length;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == "X") {
        return;
    }
    if (adj[i][j] == 1) {
        return;
    }
    adj[i][j] = 1;
    dfs(board, adj, i + 1, j);
    dfs(board, adj, i - 1, j);
    dfs(board, adj, i, j + 1);
    dfs(board, adj, i, j - 1);
}

var solve = function (board) {
    let m = board.length;
    let n = board[0].length;
    let adj = Array.from({ length: m }, () => Array(n).fill(0));

    // for first row and last row;
    for (let j = 0; j < n; j++) {
        // for first row
        if (adj[0][j] != 1 && board[0][j] == "O") {
            dfs(board, adj, 0, j);
        }
        // for last row;
        if (adj[m - 1][j] != 1 && board[m - 1][j] == "O") {
            dfs(board, adj, m - 1, j);
        }
    }
    // for first col and last col
    for (let i = 0; i < m; i++) {
        // for first col;
        if (adj[i][0] != 1 && board[i][0] == "O") {
            dfs(board, adj, i, 0);
        }
        // for last column
        if (adj[i][n - 1] != 1 && board[i][n - 1] == "O") {
            dfs(board, adj, i, n - 1);
        }
    }

    // now visit the entire board;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (adj[i][j] == 0 && board[i][j] == "O") {
                board[i][j] = "X";
            }
        }
    }
};

