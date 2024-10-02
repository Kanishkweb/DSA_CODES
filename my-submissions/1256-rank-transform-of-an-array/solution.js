/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function (arr) {
  let test = Array.from(arr);
  arr.sort((a, b) => {
    return a - b;
  });
  let map = {};
  let rank = 1;
  for (let i = 0; i < arr.length; i++) {
    if (!map[arr[i]]) {
      map[arr[i]] = rank++;
    }
  }
  let result = [];
  for (let i = 0; i < test.length; i++) {
    result.push(map[test[i]]);
  }
  return result;
};
