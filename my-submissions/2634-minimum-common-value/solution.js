/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var getCommon = function (nums1, nums2) {
    let result = -1;
    // loop for iterating in the nums1 and num2 array
    let i = 0;
    let j = 0;
    while (nums1.length > i && nums2.length > j) {
        if (nums1[i] === nums2[j]) {
            return nums1[i];
        } else if (nums1[i] < nums2[j]) {
            i++
        } else {
            j++
        }
    }
    return result;
}

