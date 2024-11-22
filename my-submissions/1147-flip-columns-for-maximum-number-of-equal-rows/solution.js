/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxEqualRowsAfterFlips = function (matrix) {
    const n = matrix.length;
    const m = matrix[0].length;
    const map = new Map();

    for (const row of matrix) {
        let temp = "";
        for (let j = 0; j < m; j++) {
            temp += (row[j] === row[0] ? '1' : '0');
        }
        map.set(temp, (map.get(temp) || 0) + 1);
    }

    let maxi = 0;
    for (const count of map.values()) {
        maxi = Math.max(maxi, count);
    }

    return maxi;

};
