/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function (nums) {
    // first step is to make the array sorted;
    let len = nums.length;
    if(len <= 4) return 0;
    nums.sort((a, b) => {
        return a - b;
    });
    // now find the smallest and the largest no in the array;
    let result = Infinity;
    for (let i = 0; i < 4; i++) {
        result = Math.min(result,nums[len -1 - 3 + i] - nums[i]);
    };
    return result;
};
