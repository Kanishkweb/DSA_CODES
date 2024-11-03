/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
// JavaScript
function rotateString(s, goal) {
    if (s.length !== goal.length) {
        return false;
    }
    return (s + s).includes(goal);
}
