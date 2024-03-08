/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function (answers) {
    let obj = {};
    for (let i = 0; i < answers.length; i++) {
        const element = answers[i];
        if (!obj[element]) {
            obj[element] = 1;
        } else {
            obj[element]++;
        }
    }
    // Asume the key each of only one color
    let keys = Object.keys(obj);
    let freqs = Object.values(obj);
    let totalRabit = 0;
    // here the main logic start
    // iterate over key and freq array key.length and freq.length always be same
    for (i = 0; i < keys.length; i++) {
        let key = parseInt(keys[i]);
        let freq = freqs[i];
        if (key == 0) {
            totalRabit += 1 * freq;
        }
        if (key > 0) {
            if (key + 1 >= freq) {
                totalRabit += key + 1;
            } else if (key + 1 < freq) {
                // cheak even odd
                if (freq % 2 == 0) {
                    // even
                    let keyPlusOne = key + 1
                    totalRabit += keyPlusOne * Math.ceil(freq / keyPlusOne);
                } else {
                    // odd
                    totalRabit += (key + 1) * Math.ceil(freq / (key + 1));;
                }
            }
        }
    }
    return totalRabit;
};
