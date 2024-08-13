/**
 * @param {string[]} grid
 * @return {number}
 */
function fill(matrix, sign, row, col) {
    if (sign == "/") {
        matrix[0 + row][2 + col] = 1;
        matrix[1 + row][1 + col] = 1;
        matrix[2 + row][0 + col] = 1;
    }
    if (sign == "\\") {
        matrix[0 + row][0 + col] = 1;
        matrix[1 + row][1 + col] = 1;
        matrix[2 + row][2 + col] = 1;
    }
    for (let i = row; i < row + 3; i++) {
        for (let j = col; j < col + 3; j++) {
            if (matrix[i][j] != 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

function dfs(matrix, row, col) {
    matrix[row][col] = 1; // for  visited;
    const directions = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0], // east // south // west // north
    ];
    let dir = 0;
    for (dir of directions) {
        let x = row + dir[0];
        let y = col + dir[1];
        if (
            x >= 0 &&
            y >= 0 &&
            x < matrix.length &&
            y < matrix.length &&
            matrix[x][y] == 0
        ) {
            dfs(matrix, x, y);
        }
    }
}
var regionsBySlashes = function (grid) {
    // step 1 - is to create a matrix;
    let row = grid.length;
    let col = grid.length;
    let matrix = Array(row * 3)
        .fill()
        .map(() => Array(col * 3).fill());
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid.length; j++) {
            if (grid[i][j] == " ") {
                fill(matrix, " ", i * 3, j * 3);
            } else if (grid[i][j] == "/") {
                fill(matrix, "/", i * 3, j * 3);
            } else if (grid[i][j] == "\\") {
                fill(matrix, "\\", i * 3, j * 3);
            }
        }
    }

    let count = 0;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix.length; j++) {
            if (matrix[i][j] == 0) {
                count++;
                // call the dfs function
                dfs(matrix, i, j);
            }
        }
    }
    return count;
};
