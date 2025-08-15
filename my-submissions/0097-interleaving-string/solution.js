/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
function solve(s1, s2, s3, map) {
    let key = s1 + "|" + s2;
    if (map.has(key)) return map.get(key);
    let n = s3.length;
    if (n == 0) return true;

    for (let i = 1; i <= n; i++) {
        let str = s3.substring(0, i);
        if (s1.length > 0) {
            let str1 = s1.substring(0, i);
            if (str == str1) {
                if (solve(s1.substring(i), s2, s3.substring(i), map)) {
                    map.set(key, true);
                    return true;
                }
            }
        }
        if (s2.length > 0) {
            let str2 = s2.substring(0, i);
            if (str == str2) {
                if (solve(s1, s2.substring(i), s3.substring(i), map)) {
                    map.set(key, true);
                    return true;
                }
            }
        }
    }
    // otherwise return false
    map.set(key, false);
    return false;
}

var isInterleave = function (s1, s2, s3) {
    if (s1.length + s2.length != s3.length) return false;
    let map = new Map();
    return solve(s1, s2, s3, map);
};
