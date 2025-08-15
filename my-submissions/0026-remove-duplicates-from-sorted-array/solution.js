/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
let n = nums.length;
  let set = new Set(nums);
  let arr = Array.from(set);
  for(let i = 0;i<n;i++){
    nums[i] = arr[i];
  }
  let k = arr.length;
  return k;
};
