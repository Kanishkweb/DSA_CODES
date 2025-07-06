/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function solve(candidates, target, index, temp, result) {
  // base case
  let n = candidates.length;
  if (target == 0) {
    result.push([...temp]);
    return 1;
  } else if (target < 0) {
    return 0;
  }
  if (index == n) {
    return 0;
  }
  temp.push(candidates[index]);
  solve(candidates, target - candidates[index], index, temp, result);
  temp.pop();
  solve(candidates, target, index + 1, temp, result);

  return;
}

var combinationSum = function (candidates, target) {
  let result = [];
  solve(candidates, target, 0, [], result);
  return result;
};
