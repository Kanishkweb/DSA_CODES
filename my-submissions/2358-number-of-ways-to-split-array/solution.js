/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) {
    let count = 0
    const prefix = Array(nums.length + 1).fill(0)

    for(let i=0; i<nums.length; i++){
        prefix[i+1] = prefix[i] + nums[i]
    }

    for(let i=0; i<nums.length-1; i++){
        const slpit_index = i + 1
        const left_sum = prefix[slpit_index] - prefix[0]
        const right_sum = prefix[prefix.length-1] - prefix[slpit_index]

        if(left_sum >= right_sum) count++
    }

    return count
};
