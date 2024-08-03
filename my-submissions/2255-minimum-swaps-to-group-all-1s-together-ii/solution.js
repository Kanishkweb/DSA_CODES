/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function (nums) {
    let totalOnes = 0;
    let currOnes = 0;
    let temp = -Infinity;
    let i = 0;
    let j = 0;
    // now lets count the total Ones
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == 1) totalOnes++;
    }
    if(totalOnes == 0) return 0;
    let len = nums.length;
    // now append the same array for the circular array
    for (let i = 0; i < len; i++) {
        nums.push(nums[i]);
    }
    // now we know the window size is the total ones we have  to append the same array
    let windowSize = 0;
    // function to count the currOnes and make window size properly
    while (windowSize < totalOnes) {
        windowSize = j - i + 1;
        if (nums[j] == 1) currOnes++;
        if (windowSize < totalOnes) j++;
    }
    while (j < nums.length) {
        // first we have to make the window size to totalOOnes
        windowSize = j - i + 1;
        if (windowSize < totalOnes) {
            if (nums[j] == 1) {
                currOnes++;
            }
            j++;
        } else if (windowSize == totalOnes) {
            if (nums[i] == 1) currOnes--;
            i++;
            j++;
            if (nums[j] == 1) currOnes++;
        }
        temp = Math.max(temp, currOnes);
    }
    return totalOnes - temp;
};
