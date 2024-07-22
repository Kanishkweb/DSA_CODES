/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function (names, heights) {
    let obj = {};
    for (let i = 0; i < heights.length; i++) {
        obj[heights[i]] = names[i];
    }
    // now sort heights array;
    heights.sort((a, b) => {
        return b - a;
    })
    for (let i = 0; i < heights.length; i++) {
        names[i] = obj[heights[i]];
    }
    return names;
};
