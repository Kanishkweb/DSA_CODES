/**
 * @param {number} red
 * @param {number} blue
 * @return {number}
 */
var maxHeightOfTriangle = function (red, blue) {
    let op = 1;
    let height = 0;
    let red2 = red;
    let blue2 = blue;
    let height2 = 0;
    let check = true;
    do {
        if (check) {
            if (blue <= 0 || blue < op) break;
            blue = blue - op;
            op++;
            check = false;
        } else {
            if (red <= 0 || red < op) break;
            red = red - op;
            op++;
            check = true;
        }
        height++;
    } while (red > 0 || blue > 0);

    check = false;
    op = 1;
    do {
        if (check) {
            if (blue2 <= 0 || blue2 < op) break;
            blue2 = blue2 - op;
            op++;
            check = false;
        } else {
            if (red2 <= 0 || red2 < op) break;
            red2 = red2 - op;
            op++;
            check = true;
        }
        height2++;
    } while (red2 > 0 || blue2 > 0);
    // if tredue the use bluelue blueall
    // if false then use red blueall
    let result = Math.max(height, height2);
    return result;
};
