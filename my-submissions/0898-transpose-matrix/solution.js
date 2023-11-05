/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function (matrix) {
    let output = Array(matrix[0].length);
    //  Main loop for the rows
    for (col = 0; col <= matrix[0].length - 1; col++) {
        let inner = Array(matrix.length);
        output[col] = inner;

        // Loop for pushing the value of the cell
        for (row = 0; row <= matrix.length - 1; row++) {
            output[col][row] = matrix[row][col];
        }
    }
    return output;
};
