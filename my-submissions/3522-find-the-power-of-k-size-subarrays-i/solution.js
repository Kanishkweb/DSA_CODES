/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var resultsArray = function (nums, k) {
    let result = [];
    for (let i = 0; i < nums.length - k + 1; i++) {
        let subMax = -Infinity;
        let temp = nums[i];
        for (let j = i; j < i + k; j++) {
            if ((nums[j] >= nums[j + 1] && j < i + k - 1) || nums[j] != temp) {
                // this condition is for the ascending order and consecutive
                result.push(-1);
                subMax = -Infinity;
                break;
            }
            temp++;
            subMax = Math.max(subMax, nums[j]);
        }
        if (subMax >= 0) {
            result.push(subMax);
        }
    }
    return result;
};
