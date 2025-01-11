/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    const freqMap = {};
    let singleCount = 0;

    // Count frequencies of each character
    for (const c of s) {
        freqMap[c] = (freqMap[c] || 0) + 1;
    }

    // Count how many characters have an odd frequency
    for (const freq of Object.values(freqMap)) {
        if (freq % 2 === 1) {
            singleCount++;
        }
    }

    // Check if we can construct exactly k palindromes
    return singleCount <= k && k <= s.length;
};
