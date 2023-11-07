/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function (nums1, nums2) {
    let obj = {};
    // Outer loop for the nums1 array traversing
    for (i = 0; i < nums1.length; i++) {
        // 3times
        for (y = 0; y < nums2.length; y++) {
            // 5times
            if (nums2[y] == nums1[i]) {
                if (!obj[nums1[i]]) {
                    obj[nums1[i]] = 1;
                } else {
                    obj[nums1[i]] += 1;
                }
            }
        }
    }
    let result = Object.keys(obj);
    return result;
};
