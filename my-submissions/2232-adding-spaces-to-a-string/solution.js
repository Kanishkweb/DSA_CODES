/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function (s, spaces) {
    let newStr = "";
    let j = 0;
    for (let i = 0; i < s.length; i++) {
        if (i == spaces[j] && j < spaces.length) {
            newStr += " ";
            newStr += s[i];
            j++;
        } else {
            newStr += s[i];
        }
    }
    return newStr;
};
