/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function (sentence) {
    // for checking first char and last char of the sentence;
    let firstChar = sentence[0];
    let lastChar = sentence[sentence.length - 1];
    if (firstChar != lastChar) {
        return false;
    }
    // step 1 - is to iterate on the given string;
    let temp = sentence.split(' ');
    for (let i = 0; i < temp.length - 1; i++) {
        let lastChar = temp[i][temp[i].length - 1];
        let nextFirstChar = temp[i + 1][0];
        if (lastChar != nextFirstChar) {
            return false;
        }
    }
    return true;
};
