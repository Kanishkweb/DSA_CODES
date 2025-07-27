/**
 * @param {string} s
 * @return {string[][]}
 */
function isPalin(s) {
    let s1 = s;
    let s2 = s.split("").reverse().join("");
    return s1 === s2;
}

function solve(s, temp, result, memo) {
    if (s.length <= 0) {
        result.push([...temp]);
        return;
    }

    for (let i = 1; i <= s.length; i++) {
        let subStr = s.substring(0, i);
        let isPalindrome = false;
        if (memo.has(subStr)) {
            isPalindrome = memo.get(subStr);
        } else {
            if (isPalin(subStr)) {
                isPalindrome = true;
            }
        }
        if (isPalindrome) {
            temp.push(subStr);
            memo.set(subStr, true);
            solve(s.substring(i), temp, result, memo);
            temp.pop();
        } else {
            memo.set(subStr, false);
        }
    }
    return result;
}

var partition = function (s) {
    let result = [];
    let memo = new Map();
    let temp = [];
    return solve(s, temp, result, memo);
};

