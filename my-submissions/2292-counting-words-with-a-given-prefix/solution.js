/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function (words, pref) {
    // step 1 
    let count = 0;
    let prefLen = pref.length;
    for (let i = 0; i < words.length; i++) {
        let word = words[i];
        if (word.length >= prefLen) {
            let temp = word.substring(0, prefLen);
            if (temp == pref) count++
        }
    }
    return count;
};
