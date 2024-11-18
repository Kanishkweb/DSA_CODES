/**
 * @param {number[]} code
 * @param {number} k
 * @return {number[]}
 */
var decrypt = function (code, k) {
    let result = [];
    code = [...code, ...code];
    let start = code.length / 2; // this is always correct due to every time even no comes
    if (k < 0) {
        k = Math.abs(k);
        // k is negative
        for (let i = start; i < code.length; i++) {
            // now make a loop to k times
            let sum = 0;
            let j = i - 1;
            for (let z = 0; z < k; z++) {
                // this loop will for the k times
                sum += code[j];
                j--;
            }
            result.push(sum);
        }
    } else if (k > 0) {
        for (let i = 0; i < code.length / 2; i++) {
            let sum = 0;
            let j = i + 1;
            for (let z = 0; z < k; z++) {
                // this loop will work  for the k times
                sum += code[j];
                j++;
            }
            result.push(sum);
        }
    } else if (k == 0) {
        for (let i = start; i < code.length; i++) {
            result.push(0);
        }
        return result;
    }
    return result;
};
