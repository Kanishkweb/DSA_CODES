/**
 * @param {number[]} nums
 * @return {number}
 */
var findScore = function (nums) {
    let score = 0;
    let smallest = [];
    for (let i = 0; i < nums.length; i++) {
        smallest.push([nums[i], i]);
    }
    smallest.sort((a, b) => {
        return a[0] - b[0];
    });
    let marked = Array(nums.length).fill(0);
    // now we have to write the main function logic start iterating from the smallest array;
    for (let i = 0; i < nums.length; i++) {
        let temp = smallest[i][0];
        let tempIndex = smallest[i][1];
        if (marked[tempIndex] != 1) {
            marked[tempIndex] = 1;
            score += temp;
            // exception cases
            if (tempIndex == 0) {
                marked[tempIndex + 1] = 1;
            } else if (tempIndex == nums.length - 1) {
                marked[tempIndex - 1] = 1;
            } else {
                // all time case
                marked[tempIndex - 1] = 1;
                marked[tempIndex + 1] = 1;
            }
        }
    }
    return score;
};
