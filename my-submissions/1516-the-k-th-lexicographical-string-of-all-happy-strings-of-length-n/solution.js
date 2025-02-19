/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getHappyString = function(n, k) {
    let happy = [];
    let chars = ['a', 'b', 'c'];

    function generateHappyString(path) {
        if (path.length === n) {
            happy.push(path);
            return;
        }
        for (let c of chars) {
            if (!path || path[path.length - 1] !== c) {
                generateHappyString(path + c);
            }
        }
    }

    generateHappyString('');
    return k > happy.length ? "" : happy[k - 1];
};
