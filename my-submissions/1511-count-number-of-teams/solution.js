/**
 * @param {number[]} rating
 * @return {number}
 */
function numTeams(rating) {
    const n = rating.length;
    const dpInc = Array.from({ length: 4 }, () => Array(n).fill(0));
    const dpDec = Array.from({ length: 4 }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        dpInc[1][i] = 1;
        dpDec[1][i] = 1;
    }

    for (let i = 2; i < 4; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < j; k++) {
                if (rating[j] > rating[k]) {
                    dpInc[i][j] += dpInc[i - 1][k];
                } else {
                    dpDec[i][j] += dpDec[i - 1][k];
                }
            }
        }
    }

    const sumArray = (arr) => arr.reduce((acc, val) => acc + val, 0);

    return sumArray(dpInc[3]) + sumArray(dpDec[3]);
}
