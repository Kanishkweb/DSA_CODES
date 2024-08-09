/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    let result = [];
    let n = matrix.length; // row
    let m = matrix[0].length; // col

    // now delcaring the direction
    let top = 0;
    let down = n - 1;
    let right = m - 1;
    let left = 0;

    // dir = 0; left to right;
    // dir = 1; top to down;
    // dir = 2; right to left;
    // dir = 3; down to top;
    let dir = 0;
    while (top <= down && left <= right) {
        if (dir == 0) {
            // left to right;
            // constant top
            for (let i = left; i <= right; i++) {
                result.push(matrix[top][i]);
            }
            top++;
        }
        if (dir == 1) {
            // top to down
            // constant right;
            for (let i = top; i <= down; i++) {
                result.push(matrix[i][right]);
            }
            right--;
        }
        if (dir == 2) {
            // right to left
            // constant down;
            for (let i = right; i >= left; i--) {
                result.push(matrix[down][i]);
            }
            down--;
        }
        if (dir == 3) {
            // down to top
            // constant left;
            for (let i = down; i >= top; i--) {
                result.push(matrix[i][left]);
            }
            left++;
        }
        dir += 1;
        if (dir == 4) dir = 0;
    }
    return result;
};
