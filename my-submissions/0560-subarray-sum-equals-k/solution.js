/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
    let count = new Map();
    count.set(0, 1);
    let currSum = 0;
    let totalSubarrays = 0;

    for (let num of nums) {
        currSum += num;
        if (count.has(currSum - k)) {
            totalSubarrays += count.get(currSum - k);
        }
        count.set(currSum, (count.get(currSum) || 0) + 1);
    }

    return totalSubarrays;
};
