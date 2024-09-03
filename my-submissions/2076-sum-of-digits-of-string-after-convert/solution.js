/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function (s, k) {
    let obj = {};
    let ct = 0;
    let alpha = "abcdefghijklmnopqrstuvwxyz";
    for (let i = 0; i < alpha.length; i++) {
        if (!obj[alpha[i]]) {
            obj[alpha[i]] = ct + 1;
            ct++;
        }
    }
    // now iterate on the s
    let str = "";
    for (let i = 0; i < s.length; i++) {
        str += obj[s[i]];
    }
    // now our str is prepared well and good;
    // acoording to the k we will decalre the ans of it.
    // we will convert string to number;
    let total = 0;
    while (k > 0) {
        k--;
        for (let i = 0; i < str.length; i++) {
            total += parseInt(str[i]);
        }
        str = total.toString();
        if (k == 0) return total;
        else total = 0;
    }
    return total;
};

