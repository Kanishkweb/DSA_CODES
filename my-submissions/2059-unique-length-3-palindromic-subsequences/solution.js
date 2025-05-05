/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function (s) {
    let init = new Map();
    let final = new Map();
    // loop for storing the values of the initial and the final positions
    for (let i = 0; i < s.length; i++) {
        if (!init.has(s[i])) {
            init.set(s[i], i);
        } else {
            final.set(s[i], i);
        }
    }

    // convert final map to array
    let finalArr = [...final.keys()];

    // step - 2
    let count = 0;
    for (let i = 0; i < finalArr.length; i++) {
        let ele = finalArr[i];
        // check the eligibility for the palindrome of 3 length;
        if (final.get(ele) > init.get(ele) + 1) {
            let substring = s.slice(init.get(ele) + 1, final.get(ele));

            let uniqueChars = new Set(substring);

            count += uniqueChars.size;
        }
    }
    return count;
};
