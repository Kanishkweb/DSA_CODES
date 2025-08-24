/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var partitionArray = function (nums, k) {
    let n = nums.length;
    if (n % k != 0) {
        return false;
    }

    let map = new Map();

    for (let i = 0; i < n; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1);
        } else {
            map.set(nums[i], 1);
        }
    }

    // now iterate map;
    for (let [key, value] of map) {
        if (n / k < value) {
            return false;
        }
    }
    if (n % k == 0) return true;
};
