/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function (nums) {
    let obj = {};
    // iterate over the array
    for (i = 0; i < nums.length; i++) {
        let element = nums[i];
        if (obj[element]) {
            obj[element]++;
        } else {
            obj[element] = 1;
        }
    }
    let keys = Object.keys(obj);
    let freqs = Object.values(obj);
    let totalMax = 0;
    let result = 0;
    // iterate over the keys and freq to find the maximum
    // main freq
    for (i = 0; i < keys.length; i++) {
        let freq = freqs[i];
        totalMax = Math.max(totalMax, freq);
    }
    for (i = 0; i < keys.length; i++) {
        let freq = freqs[i];
        if (freq == totalMax) {
            result += freq;
        }
    }
    return result;
}
