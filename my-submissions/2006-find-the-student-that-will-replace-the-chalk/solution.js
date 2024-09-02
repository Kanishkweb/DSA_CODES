/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */
var chalkReplacer = function (chalk, k) {
    let i = 0;
    let ttCk = 0;
    for(let i = 0;i<chalk.length;i++){
        ttCk += chalk[i];
    }
    while(k - ttCk > 0){
        k = k - ttCk
    }
    while (true) {
        if (k < 0 || k - chalk[i] < 0) return i;
        k = k - chalk[i];
        i = (i + 1) % chalk.length;
    }
};
