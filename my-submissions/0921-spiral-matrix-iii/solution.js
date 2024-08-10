/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
const directions = [
    [0, 1], // right // east
    [1, 0], // down // south
    [0, -1], // left // west
    [-1, 0], // up // north
];

var spiralMatrixIII = function (rows, cols, rStart, cStart) {
    const size = rows * cols;
    let dir = 0; // start the direction from the east 
    let steps = 0;
    const res = [[rStart, cStart]];
    while (res.length < size) {
        if(dir == 0 || dir == 2) steps++;
        for(let i = 0;i<steps;i++){
            rStart += directions[dir][0] // x 
            cStart += directions[dir][1] // y
            if(rStart < rows && cStart < cols && rStart >= 0 && cStart >= 0){
                res.push([rStart,cStart]);
            }
        }
        dir = (dir+1)%4;
    }

    return res;
};
