/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
    // iterate on string a and b;
    let i = a.length - 1;
    let j = b.length - 1;
    let ans = "";
    let carry = 0;
    while (i >= 0 || j >= 0) {
        // condition for 1
        if ((a[i] == 0 && b[j] == 1) || (a[i] == 1 && b[j] == 0)) {
            if (carry == 1) {
                ans = "0" + ans;
                carry = 1;
            } else {
                ans = "1" + ans;
            }
        } else if (a[i] == 1 && b[j] == 1) {
            if (carry == 1) {
                ans = "1" + ans;
                carry = 1;
            } else {
                ans = "0" + ans;
                carry = 1;
            }
        } else if (a[i] == 0 && b[j] == 0) {
            if (carry == 1) {
                ans = "1" + ans;
                carry = 0;
            } else {
                ans = "0" + ans;
            }
        } else {
            let op;
            if (a[i]) {
                op = a[i];
            } else {
                op = b[j];
            }
            if (carry == 1 && op == "1") {
                ans = "0" + ans;
                // carry = 1;
            } else if (carry == 1 && op == "0") {
                ans = "1" + ans;
                carry = 0;
            } else {
                ans = op.toString() + ans;
            }
        }
        i--, j--;
    }
    if (carry == 1) ans = "1" + ans;
    return ans;
};
