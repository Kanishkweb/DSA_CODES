/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function (logs) {
    let stk = [];
    // Iterate on the list logs;
    for (let i = 0; i <= logs.length - 1; i++) {
        if (logs[i] == "../") {
            stk.pop();
        } else if (logs[i] == "./") {
            continue;
        } else {
            stk.push(logs[i]);
        }
    }
    return stk.length;
};
