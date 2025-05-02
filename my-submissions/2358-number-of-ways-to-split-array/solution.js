/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function (nums) {
    let prefix = [];
    let sum = 0;
    // store the sum in prefexSum Arr
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        prefix.push(sum);
    }
    // all prefixSum stored successfully
    // now step -2 
    let n = nums.length - 1;
    let count = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        let split = i;
        if (prefix[split] >= prefix[n] - prefix[split]) {
            count++;
        }
    }
    return count;
};
