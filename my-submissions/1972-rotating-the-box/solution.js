/**
 * @param {character[][]} box
 * @return {character[][]}
 */

var rotateTheBox = function (box) {
    const row = box.length, col = box[0].length;
    const box_90 = Array.from({ length: col }, () => Array(row).fill(''));

    // Simulate gravity
    for (let i = 0; i < row; i++) {
        let cell = col - 1;
        for (let j = col - 1; j >= 0; j--) {
            if (box[i][j] === '*') {
                cell = j - 1;
            } else if (box[i][j] === '#') {
                box[i][j] = '.';
                box[i][cell--] = '#';
            }
        }
    }

    // Rotate the box 90 degrees clockwise
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            box_90[j][row - i - 1] = box[i][j];
        }
    }

    return box_90;
};
