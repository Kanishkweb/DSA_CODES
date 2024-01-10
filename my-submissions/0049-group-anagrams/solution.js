/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    let obj = {};
    let newStrs = [];
    // Loop for iterating and performing iteration on the array strs;
    for (i = 0; i < strs.length; i++) {
        let arr = Array.from(strs[i]);
        arr.sort();
        newStrs[i] = arr.join("");
        // Code for storing values in obj
        if (obj[newStrs[i]]) {
            let arr = obj[newStrs[i]];
            arr.push(strs[i]);
            obj[newStrs[i]] = arr;
        } else {
            obj[newStrs[i]] = [strs[i]];
        }
    }

    return Object.values(obj);
};
