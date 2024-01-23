/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function (nums) {
    // iterate over the array
    let l = 0;
    let h = nums.length - 1;
    let ans;

    if (h == 0) return 0; // for one length array
    if (h == 1) {
        // for two length array
        ans = Math.max(nums[0], nums[1]);
        return nums.indexOf(ans);
    }
    while (h >= l) {
        let mid = l + Math.floor((h - l) / 2);
        // case for the -infinity at 0 index
        if (mid <= 0 && nums[mid + 1] < nums[mid]) return mid;
        // case for the -infinity at last index
        if (mid == nums.length - 1 && nums[mid - 1] < nums[mid]) return mid;
        // first condition
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        // check where to go left or right
        if (nums[mid] < nums[mid + 1]) {
            // go to the right array
            l = mid + 1;
        } else if (nums[mid - 1] > nums[mid]) {
            // go to the left array
            h = mid - 1;
        }
    }
};
