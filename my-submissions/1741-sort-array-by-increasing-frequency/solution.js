/**
 * @param {number[]} nums
 * @return {number[]}
 */

var frequencySort = function(nums) {
    const freqMap = new Map();
    
    // Count the frequency of each number
    nums.forEach(num => {
        freqMap.set(num, (freqMap.get(num) || 0) + 1);
    });
    
    // Sort based on frequency and value
    nums.sort((a, b) => {
        const freqA = freqMap.get(a);
        const freqB = freqMap.get(b);
        if (freqA !== freqB) {
            return freqA - freqB; // Sort by frequency
        } else {
            return b - a; // Sort by value in decreasing order
        }
    });
    
    return nums;
};
