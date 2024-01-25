/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    let l = 1;
    let h = x;
    let ans;
    if (x == 0) return 0
    while (h >= l) {
        let mid = l + Math.floor((h - l) / 2);
        if (mid * mid > x) {
            // Go to the left region
            h = mid - 1;
        } else {
            // Go to the right region
            l = mid + 1;
            ans = mid;
        }
    }
    return ans;
};
