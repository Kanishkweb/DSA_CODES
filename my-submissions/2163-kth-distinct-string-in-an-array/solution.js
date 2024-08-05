/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    let map = {};
    let dS = [];
    for (let i = 0; i < arr.length; i++) {
        if (!map[arr[i]]) {
            map[arr[i]] = 1
        } else {
            map[arr[i]]++
        }
    }
    for (let i = 0; i < arr.length; i++) {
        if (map[arr[i]] == 1) dS.push(arr[i]);
    }
    if (dS.length < k) return "";
    else return dS[k - 1]
};
