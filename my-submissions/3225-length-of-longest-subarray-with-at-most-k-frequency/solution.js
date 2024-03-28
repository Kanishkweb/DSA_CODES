/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubarrayLength = function (nums, k) {
  let obj = {};
  let windowSize = 0;
  let start = -1;
  let end = 0;
  // step - 1; iterate on array;
  for (let i = 0; i < nums.length; i++) {
    if (obj[nums[i]] < k) {
      obj[nums[i]]++;
    } else if (!obj[nums[i]]) {
      obj[nums[i]] = 1;
      // if the freq of the element is greator than k then
    } else if (obj[nums[i]] >= k) {
      obj[nums[i]]++;
      while (obj[nums[i]] != k) {
        start++;
        obj[nums[start]]--;
      }
    }
    windowSize = Math.max(windowSize, i - start);
  }
  return windowSize;
};
