/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function (nums, k) {
    let start = -1;
    let cnt = 0;
    let n = nums.length;
    let result = 0;
    let maxEle = 0;
    // step-1 find the maximum element;
    for (let i = 0; i < nums.length; i++) {
        maxEle = Math.max(maxEle, nums[i]);
    }
    // iterate over the array
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == maxEle) {
            cnt++;
        }
        while (cnt >= k) {
            start++;
            if (nums[i] == nums[start]) {
                cnt--;
            }
            result += n - i;
        }
    }
    return result;
};
