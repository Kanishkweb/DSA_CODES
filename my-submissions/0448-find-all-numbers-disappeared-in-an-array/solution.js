/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function (nums) {
    let result = [];
    let obj = {};
    // This for loop for pushing all the value till n [1,n]
    for (i = 0; i <= nums.length - 1; i++) {
        if (!obj[i + 1]) {
            obj[i + 1] = 1;
        }
    }
    // This for loop is for pushing the available value in the loop
    for (i = 0; i <= nums.length - 1; i++) {
        if (obj[nums[i]]) {
            obj[nums[i]]++;
        }
    }
    // Now loop for printing the result
    for (i = 0; i <= nums.length - 1; i++) {
        if (obj[i + 1] == 1) {
            let value = i + 1;
            result.push(value);
        }
    }
    return result;
};
