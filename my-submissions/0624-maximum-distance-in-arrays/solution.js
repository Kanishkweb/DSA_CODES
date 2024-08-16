/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function (arr) {
    let min = arr[0][0];
    let max = arr[0][arr[0].length - 1];
    let maxDist = 0;

    for (let i = 1; i < arr.length; i++) {
        let currMin = arr[i][0];
        let currMax = arr[i][arr[i].length - 1];

        maxDist = Math.max(maxDist, Math.abs(currMax - min), Math.abs(max - currMin));

        min = Math.min(min, currMin);
        max = Math.max(max, currMax);
    }

    return maxDist;
};
