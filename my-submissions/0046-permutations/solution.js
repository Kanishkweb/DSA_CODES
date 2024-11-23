/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
    let result = [];
    function backtrack(nums, temp) {
        if (temp.size == nums.length) {
            let arr = Array.from(temp);
            result.push([...arr]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            // do
            let currEle = nums[i];
            // let newNum = nums.filter((element) => element !== currEle);
            if (temp.has(currEle)) {
                continue;
            } else {
                temp.add(nums[i]); // add the curr element
            }
            // explore
            backtrack(nums, temp);
            temp.delete(currEle);
        }
        return result;
    }
    return backtrack(nums,new Set())
};
