/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function (s, x, y) {
    let stack = [];
    let totalx = 0;
    let totaly = 0;
    // iterate on the string s
    if (y >= x) {
        for (let i = 0; i < s.length; i++) {
            // code for ba calc
            if (s[i] == "a" && stack[stack.length - 1] == "b") {
                totaly += y;
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }
        let tempy = "";
        for (let i = 0; i < stack.length; i++) {
            tempy += stack[i];
        }
        stack = [];
        for (let i = 0; i < tempy.length; i++) {
            if (tempy[i] == "b" && stack[stack.length - 1] == "a") {
                totaly += x;
                stack.pop();
            } else {
                stack.push(tempy[i]);
            }
        }
    }

    // code for ab calc

    if (x >= y) {
        stack = [];
        for (let i = 0; i < s.length; i++) {
            // code for ab calc
            if (s[i] == "b" && stack[stack.length - 1] == "a") {
                totalx += x;
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }

        let tempx = "";
        for (let i = 0; i < stack.length; i++) {
            tempx += stack[i];
        }
        stack = [];
        for (let i = 0; i < tempx.length; i++) {
            if (tempx[i] == "a" && stack[stack.length - 1] == "b") {
                totalx += y;
                stack.pop();
            } else {
                stack.push(tempx[i]);
            }
        }
    }
    return Math.max(totaly, totalx);
};
