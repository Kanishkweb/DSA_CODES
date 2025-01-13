/**
 * @param {string} s
 * @return {number}
 */
function minimumLength(s) {
    const n = s.length;
    let removableLen = 0;
    const freq = Array(26).fill(0);

    for (let i = 0; i < n; i++) {
        freq[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    for (const frequency of freq) {
        if (frequency % 2 !== 0) {
            removableLen += frequency - 1;
        } else if (frequency !== 0) {
            removableLen += frequency - 2;
        }
    }

    return n - removableLen;
}
