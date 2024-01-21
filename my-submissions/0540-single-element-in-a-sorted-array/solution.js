/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function (nums) {
    let l = 0;
    let h = nums.length - 1;
    let ans;
    while (h >= l) {
        let mid = l + Math.floor((h - l) / 2);
        /**
         * Even index means 1st
         * Odd index means 2nd
         */

        // Cheak if mid is pre ans or not
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];

        // this code cheak even
        if (mid % 2 == 0) {
            // second must be present after it
            if (nums[mid] == nums[mid + 1]) {
                // Element double present
                // go for the right region
                ans = mid;
                l = mid + 1;
            } else {
                // go for the left region
                ans = mid;
                h = mid - 1;
            }
            // this code for odd
        } else {
            if (nums[mid] == nums[mid - 1]) {
                // go for the right region
                ans = mid;
                l = mid + 1;
            } else {
                // go for the left region
                ans = mid;
                h = mid - 1;
            }
        }
    }
    return nums[ans];
};
