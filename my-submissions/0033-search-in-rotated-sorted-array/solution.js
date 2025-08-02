/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function binarySearch(nums, target, l, r) {
    while (l <= r) {
        let mid = l + Math.floor((r - l) / 2);
        if (nums[mid] == target) {
            return mid;
        }
        // now find the target element
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

var search = function (nums, target) {
    let l = 0;
    let r = nums.length - 1;
    let pivot = 0; // for intializer
    while (l < r) {
        let mid = l + Math.floor((r - l) / 2);

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    pivot = l;
    // our pivot is ready;
    r = nums.length - 1;
    let idx = -1;
    idx = binarySearch(nums, target, 0, pivot - 1);
    // binary search on the right side;
    if (idx != -1) return idx;
    idx = binarySearch(nums, target, pivot, r);
    return idx;
};
