/**
 * @param {string} s
 * @param {string} locked
 * @return {boolean}
 */
var canBeValid = function(s, locked) {
    if (s.length % 2 !== 0) return false;

    let balance = 0;
    for (let i = 0; i < s.length; i++) {
        if (locked[i] === '0' || s[i] === '(') {
            balance++;
        } else if (s[i] === ')') {
            balance--;
        }
        if (balance < 0) return false;
    }

    balance = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        if (locked[i] === '0' || s[i] === ')') {
            balance++;
        } else if (s[i] === '(') {
            balance--;
        }
        if (balance < 0) return false;
    }

    return true;
};
