/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) {
        return false;
    }
    let arrS = Array.from(s);
    arrS.sort();
    let arrT = Array.from(t);
    arrT.sort();
    let strS = arrS.join("");
    let strT = arrT.join("");
    if (strS === strT) {
        return true;
    } else {
        return false;
    }
};
