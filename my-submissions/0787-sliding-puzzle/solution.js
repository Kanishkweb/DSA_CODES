/**
 * @param {number[][]} board
 * @return {number}
 */
var slidingPuzzle = function(board) {
    const dr = [0, 1, 0, -1];
    const dc = [-1, 0, 1, 0];
    const target = [[1, 2, 3], [4, 5, 0]];
    let r, c;

    // Find position of empty cell (0)
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i][j] === 0) {
                r = i;
                c = j;
            }
        }
    }

    const queue = [{ row: r, col: c, board, steps: 0 }];
    const visited = new Set();
    visited.add(JSON.stringify(board));

    // BFS loop
    while (queue.length > 0) {
        const { row, col, board, steps } = queue.shift();
        if (JSON.stringify(board) === JSON.stringify(target)) return steps;

        for (let i = 0; i < 4; i++) {
            const newRow = row + dr[i];
            const newCol = col + dc[i];
            if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                const newBoard = board.map(row => [...row]);
                [newBoard[row][col], newBoard[newRow][newCol]] = [newBoard[newRow][newCol], newBoard[row][col]];

                const newBoardStr = JSON.stringify(newBoard);
                if (!visited.has(newBoardStr)) {
                    queue.push({ row: newRow, col: newCol, board: newBoard, steps: steps + 1 });
                    visited.add(newBoardStr);
                }
            }
        }
    }

    return -1;
};
