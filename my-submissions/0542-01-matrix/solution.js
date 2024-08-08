/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function (mat) {
    let n = mat.length; // row
    let m = mat[0].length; // col
    let q = [] // initailizing array queue
    let ans = Array(n).fill().map(() => Array(m).fill());
    // undifined matrix created
    // now push the zero to the ans matrix
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                ans[i][j] = 0;
                // also push this indexing to the queue;
                q.push([i, j]);
            }
        }
    }
    while (q.length) {  // when the queue is not becomes the zero then the loop will work continue 0 == false
        let [x, y] = q.shift();  // dequeue the first element from the queue;
        // for downward direction
        if (x + 1 < n && ans[x + 1][y] == undefined) {
            ans[x + 1][y] = ans[x][y] + 1;
            // also push this in the queue
            q.push([x + 1, y]);
        }
        // for upward direction
        if (x - 1 >= 0 && ans[x - 1][y] == undefined) {
            ans[x - 1][y] = ans[x][y] + 1;
            q.push([x - 1, y]);
        }
        // for left direction
        if (y - 1 >= 0 && ans[x][y - 1] == undefined) {
            ans[x][y - 1] = ans[x][y] + 1;
            q.push([x, y - 1]);
        }
        // for the right direction
        if (y + 1 < m && ans[x][y + 1] == undefined) {
            ans[x][y + 1] = ans[x][y] + 1;
            q.push([x, y + 1])
        }
    }
    return ans;
};
