/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function (nums) {
    let n = nums.length;
    let totalPairs = (n * (n - 1)) / 2; // Total possible pairs
    let goodPairs = 0;
    let map = new Map();

    for (let i = 0; i < n; i++) {
        let key = nums[i] - i;
        if (map.has(key)) {
            goodPairs += map.get(key);
            map.set(key, map.get(key) + 1);
        } else {
            map.set(key, 1);
        }
    }

    return totalPairs - goodPairs;
};
