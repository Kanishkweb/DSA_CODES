/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function (original, m, n) {
    let matrix = [];
    let count = 0;
    // for rows;
    for (let i = 0; i < m; i++) {
        matrix.push([]);
        for (let j = 0; j < n; j++) {
            let temp = original[count];
            matrix[i].push(temp);
            count++;
        }
    }
    if(count != original.length) return [];
    else return matrix;
};
