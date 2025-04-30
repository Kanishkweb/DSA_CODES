/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function (s) {
    // count no of 1;
    let left = 0;
    let right = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] == "1") right++;
    }
    let score = 0;
    for (let i = 0; i < s.length-1; i++) {
        if (s[i] == "0") left++;
        else right--;

        score = Math.max(score, left + right);
    }
    return score;
};
