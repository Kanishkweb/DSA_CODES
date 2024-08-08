/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
const directions = [
    [0, 1], // right
    [1, 0], // down
    [0, -1], // left
    [-1, 0], // up
];

var spiralMatrixIII = function (rows, cols, rStart, cStart) {
    const size = rows * cols;
    const res = [[rStart, cStart]];

    let row = rStart;
    let col = cStart;
    let rightDown = 1;
    let leftUp = 2;
    while (res.length < size) {
        for (let i = 0; i < directions.length; i++) {
            if (i <= 1) {
                // right down
                for (let j = 0; j < rightDown; j++) {
                    row += directions[i][0];
                    col += directions[i][1];

                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        res.push([row, col]);
                    }
                }
            } else {
                // left up
                for (let j = 0; j < leftUp; j++) {
                    row += directions[i][0];
                    col += directions[i][1];

                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        res.push([row, col]);
                    }
                }
            }
        }

        // update the pattern
        rightDown += 2;
        leftUp += 2;
    }

    return res;
};
