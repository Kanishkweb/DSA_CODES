function check(firstChar, lastChar) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    return vowels.has(firstChar) && vowels.has(lastChar) ? 1 : 0;
}

var vowelStrings = function (words, queries) {
    let prefix = new Array(words.length).fill(0);
    let cumu = 0;

    for (let i = 0; i < words.length; i++) {
        let firstChar = words[i][0];
        let lastChar = words[i][words[i].length - 1];
        cumu += check(firstChar, lastChar);
        prefix[i] = cumu;
    }

    let ans = [];
    for (let [l, r] of queries) {
        if (l === 0) {
            ans.push(prefix[r]);
        } else {
            ans.push(prefix[r] - prefix[l - 1]);
        }
    }
    return ans;
};

