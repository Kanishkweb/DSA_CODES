/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function (s, goal) {
    let temp = s.split("");
    for (let i = 0; i < s.length; i++) {
        let op = temp.shift();
        temp.push(op);
        // now change the array into the string;
        let str = temp.join("");
        if (str === goal) return true;
    }
    return false;
};
