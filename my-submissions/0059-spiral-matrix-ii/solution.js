/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function (n) {
    // create a matrix of the result;
    let matrix = Array(n)
        .fill()
        .map(() => Array(n).fill());
    // matrix created with undefined elements;
    // now we have to traverse in an spiral order;
    // dir = 0 left to right;
    // dir = 1; top to down;

    // dir = 2 right to left;
    // dir = 3; down to top;
    let top = 0;
    let down = n - 1;
    let left = 0;
    let right = n - 1;
    let dir = 0;
    let num = 1;
    while (top <= down && left <= right && num <= n * n) {
        if (dir == 0) {
            // left to right;
            // constant top;
            for (let i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;
        }
        if (dir == 1) {
            // top to down;
            // constant right;
            for (let i = top; i <= down; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;
        }
        if (dir == 2) {
            // right to left;
            // constant down;
            for (let i = right; i >= left; i--) {
                matrix[down][i] = num;
                num++;
            }
            down--;
        }
        if (dir == 3) {
            // down to top;
            // constant left;
            for (let i = down; i >= top; i--) {
                matrix[i][left] = num;
                num++;
            }
            left++;
        }
        if (dir == 4) dir = 0;
        else dir += 1;
    }
    return matrix;
};

