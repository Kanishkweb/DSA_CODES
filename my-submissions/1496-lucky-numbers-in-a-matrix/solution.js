/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function (matrix) {
    // loop for iterating in the row
    let rowL = matrix.length;
    let colL = matrix[0].length;
    let minA = [];
    let maxA = [];
    for (let i = 0; i < rowL; i++) {
        let minRow = Infinity;
        for (let j = 0; j < colL; j++) {
            // step - 1 - is to find the row
            minRow = Math.min(minRow, matrix[i][j]);
        }
        minA.push(minRow);
    }
    for (let j = 0; j < colL; j++) {
        let maxCol = -Infinity;
        for (let i = 0; i < rowL; i++) {
            // step - 1 - is to find the row
            maxCol = Math.max(maxCol, matrix[i][j]);
        }
        maxA.push(maxCol);
    }
    for (let i = 0; i < minA.length; i++) {
        for (let j = 0; j < maxA.length; j++) {
            if (minA[i] == maxA[j]) {
                return [minA[i]];
            }
        }
    }
    return [];
};
