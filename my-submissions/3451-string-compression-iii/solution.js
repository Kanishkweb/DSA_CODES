/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function (word) {
    let comp = "";
    let lastChar = word[0];
    let count = 0;
    for (let i = 0; i < word.length; i++) {
        let char = word[i];
        if (lastChar == char && count < 9) {
            count++;
        } else {
            comp += count + lastChar;
            lastChar = char;
            count = 1;
        }
    }
    comp += count + lastChar;
    return comp;
};
