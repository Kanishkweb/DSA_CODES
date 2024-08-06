/**
 * @param {string} word
 * @return {number}
 */
var minimumPushes = function (word) {
    let map = {};
    let arr = [];
    let total = 0;
    // we need to store how many times it comes in the word string;
    for (let i = 0; i < word.length; i++) {
        if (!map[word[i]]) {
            map[word[i]] = 1;
            arr.push(word[i]);
        } else {
            map[word[i]]++;
        }
    }
    if (arr.length <= 8) {
        for (let i = 0; i < arr.length; i++) {
            total += map[arr[i]];
        }
        return total;
    }
    // now sort the arr word according to the higher frequency;
    arr.sort((a, b) => {
        return map[b] - map[a];
    });
    // if arr.length is > 8 then alot the aphabet according to the higher freq;
    for (let i = 0; i < arr.length; i++) {
        if (i <= 7) {
            total += map[arr[i]];
        } else if (i <= 15) {
            total += map[arr[i]] * 2;
        } else if (i <= 23) {
            total += map[arr[i]] * 3;
        } else {
            total += map[arr[i]] * 4;
        }
    }
    return total;
};
