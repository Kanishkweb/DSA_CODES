/**
 * @param {string} s
 * @return {string[][]}
 */

function isPalin(s) {
    let s1 = s;
    // reverse the string in s2;
    let s2 = s.split("").reverse().join("");
    return s1 == s2;
}

function solve(s, partition, result) {
    if (s.length == 0) {
        result.push([...partition]);
        return;
    }

    for (let i = 0; i < s.length; i++) {
        let subStr = s.substring(0, i + 1);
        if (isPalin(subStr)) {
            partition.push(subStr);
            solve(s.substring(i + 1), partition, result);
            partition.pop();
        }
    }
}


var partition = function (s) {
    let result = [];
    solve(s, [], result);
    return result;
};
