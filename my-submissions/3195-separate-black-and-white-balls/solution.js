/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function (s) {
    let totalStep = 0;
    let lastZero;
    let i = 0;
    if (s[0] == 1) {
        lastZero = -1;
    } else {
        while (s[i] == 0) {
            lastZero = i;
            i++;
        }
    }
    for (let i = lastZero + 1; i < s.length; i++) {
        if (s[i] == 0) {
            // swap;
            let steps = i - 1 - lastZero;
            totalStep += steps;
            lastZero++;
        }
    }
    return totalStep;
};
