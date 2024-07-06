/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function (n, time) {
    let result = 1;
    if (n <= time) {
        let r = time % (n - 1);
        let q = Math.floor(time / (n - 1));
        if (q % 2 == 0) {
            result = r + 1;
        } else {
            if (r == 0) {
                result = n;
            } else {
                result = n - r;
            }
        }
    } else if (n > time) {
        result = time + 1;
    }
    return result;
}
