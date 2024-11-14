/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function (s) {
    // step 1 iterate the string;
    let temp = "";
    let count = 0;
    let strB = "";
    for (let i = 0; i < s.length; i++) {
        if (s[i] != temp) {
            // store the char in temp
            temp = s[i];
            count = 1;
        } else if (s[i] == temp && count < 2) {
            count++;
        } else if (s[i] == temp && count == 2) {
            // we have to delete this char in the string to make fancy
            continue;
        }
        strB = strB + s[i];
    }
    return strB;
};
