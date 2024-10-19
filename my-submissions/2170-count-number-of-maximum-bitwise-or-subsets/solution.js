/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function (nums) {
    let totLen = 1 << nums.length;
    let count = 0;
    let maxOR;
    for (let i = 0; i < nums.length; i++) {
        maxOR = nums[i] | maxOR;
    }

    for (i = 1; i < totLen; i++) { // for not to including non empty subsets
        let currMax = 0;
        for (j = 0; j < nums.length; j++) {
            if ((1 << j) & i) {
                currMax = currMax | nums[j];
            }
        }
        if (currMax == maxOR) {
            count++;
        }
    }
    return count;
};
