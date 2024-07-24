/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function (mapping, nums) {
    // iterate on the nums array
    let map = {};
    for (let i = 0; i < nums.length; i++) {
        let str = nums[i].toString();
        let updateStr = "";
        for (let j = 0; j < str.length; j++) {
            let clg = mapping[parseInt(str[j])];
            updateStr += clg;
        }
        // when the loop gets end print the output to the map
        if (!map[nums[i]]) {
            map[nums[i]] = parseInt(updateStr);
        }
    }
    // now the map has been successfully created
    nums.sort((a, b) => {
        freqA = map[a];
        freqB = map[b];
        return freqA - freqB;
    });
    return nums;
};
