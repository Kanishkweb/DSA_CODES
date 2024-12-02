/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
    let sentenceArr = sentence.split(' ');
    for(let i=0; i< sentenceArr.length; i++) {
        if(sentenceArr[i].startsWith(searchWord)) {
            return i+1
        }
    }
    return -1
};
