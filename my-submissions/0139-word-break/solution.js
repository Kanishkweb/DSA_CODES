/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */

function solve(s, wordDict, memo) {
    // base case
    if (s.length <= 0) {
        return true;
    }

    if (memo.has(s)) return memo.get(s);

    for (let i = 1; i <= s.length; i++) {
        let subStr = s.substring(0, i);
        if (wordDict.has(subStr)) {
            if (solve(s.substring(i), wordDict, memo)) {
                memo.set(s, true);
                return true;
            }
        }
    }
    memo.set(s, false);
    return false;
}

var wordBreak = function (s, wordDict) {
    let wordDi = new Set(wordDict);
    let memo = new Map();
    return solve(s, wordDi, memo);
};
