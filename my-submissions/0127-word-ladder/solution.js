/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
function getNeighbours(word, set) {
    let neighbours = new Set();
    //   let word = "hit";
    for (let i = 0; i < word.length; i++) {
        // 3 --> 0,1,2; (3,3)
        for (let ch of "abcdefghijklmnopqrstuvwxyz") {
            if (ch == word.charAt(i)) {
                continue;
            }
            let newWord =
                word.substring(0, i) + ch + word.substring(i + 1, word.length);
            if (set.has(newWord)) {
                neighbours.add(newWord);
            }
        }
    }
    return neighbours;
}

var ladderLength = function (beginWord, endWord, wordList) {
    // first step create a HashSet
    let set = new Set(wordList);
    if (!set.has(endWord)) {
        return 0; // false;
    }
    // create a queue;
    let queue = [];
    queue.push(beginWord);
    let temp = [];
    let level = 0;
    // if set contians beginWord them remove it;
    if (set.has(beginWord)) {
        set.delete(beginWord);
    }
    while (queue.length != 0) {
        // let getfront = queue.shift(); // getfront

        let currLevelSize = queue.length;

        for (let i = 0; i < currLevelSize; i++) {
            let string = queue.shift();
            if (string == endWord) {
                return level + 1;
            }
            let neighbours = getNeighbours(string, set);
            // adj list;
            for (let word of neighbours) {
                if (set.has(word)) {
                    queue.push(word);
                    set.delete(word);
                }
            }
        }
        level++;
    }
    return 0;
};
