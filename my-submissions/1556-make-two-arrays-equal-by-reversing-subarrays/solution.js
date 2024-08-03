/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
var canBeEqual = function (target, arr) {
    target.sort((a, b) => {
        return a - b;
    })
    arr.sort((a, b) => {
        return a - b;
    })
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] != target[i]) return false;
    }
    return true;
};
