/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function (nums) {
    nums.sort(function (a, b) {
        return a - b;
    });
    let res = 0;
    let j = nums.length - 1;
    for (i = 0; i < j; i++, j--) {
        let response = nums[i] + nums[j];
        res = Math.max(res, response)
    }
    return res;
};
