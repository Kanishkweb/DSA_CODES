/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let majorityElements = -1;
    let frequency = 0
    // Loop for traversing the whole array
    for (i = 0; i < nums.length; i++) {
        if (frequency == 0) {
            majorityElements = nums[i]
        } 
        if (majorityElements == nums[i]) {
            frequency++
        } else {
            frequency--
        }
    }
    return majorityElements
};
