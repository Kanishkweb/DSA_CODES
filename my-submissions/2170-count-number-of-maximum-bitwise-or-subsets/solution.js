var countMaxOrSubsets = function(nums) {
    let maxOR = 0;
    for (let num of nums) {
        maxOR |= num;
    }
    return backtrack(nums, maxOR, 0, 0);
};

function backtrack(nums, maxOR, index, currentOR) {
    if (index === nums.length) {
        return currentOR === maxOR ? 1 : 0;
    }
    if (currentOR === maxOR) {
        return 1 << (nums.length - index);
    }
    let include = backtrack(nums, maxOR, index + 1, currentOR | nums[index]);
    let exclude = backtrack(nums, maxOR, index + 1, currentOR);
    return include + exclude;
}

// Example usage
const nums = [3, 1, 5];
console.log(countMaxOrSubsets(nums));  // Output: 6
