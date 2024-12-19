/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function (arr) {
    let ans = 0;
    let n = arr.length;
    let max = -Infinity;
    for (let i = 0; i < n; i++) {
        max = Math.max(max, arr[i]);
        if (max < i + 1) {
            ans++;
        }
    }
    return ans;
};
