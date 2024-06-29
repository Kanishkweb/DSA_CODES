/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function (nums) {
    // we have an array nums
    let result = 0;
    for (let i = 0; i <= nums.length - 2; i++) {
        // take first three elements if needed
        if (nums[i] == 0) {
            // change the first three elements
            let op = 3;
            let j = i;
            while (op > 0) {
                if (nums[j] == 0) {
                    nums[j] = 1;
                } else {
                    nums[j] = 0;
                }
                j++;
                op--;
            }
            result++;
        }
    }
    // now cheak if all the array become 1 or not
    for (let i = 0; i <= nums.length - 1; i++) {
        if (nums[i] == 0) {
            return -1;
        }
    }
    return result;
};
