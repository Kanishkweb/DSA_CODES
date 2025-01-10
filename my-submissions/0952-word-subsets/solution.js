/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */

var wordSubsets = function(words1, words2) {
    let req = {}; // To store the max frequency of each character

    // Calculate the maximum frequency needed for each character from words2
    for (let word of words2) {
        let cur = {};
        for (let c of word) {
            cur[c] = (cur[c] || 0) + 1;
            req[c] = Math.max(req[c] || 0, cur[c]);
        }
    }

    let result = [];

    // Check each word in words1
    for (let word of words1) {
        let cur = {};
        for (let c of word) {
            cur[c] = (cur[c] || 0) + 1;
        }

        let isUniversal = true;
        for (let [ch, frq] of Object.entries(req)) {
            if ((cur[ch] || 0) < frq) {
                isUniversal = false;
                break;
            }
        }

        if (isUniversal) result.push(word);
    }

    return result;
};
