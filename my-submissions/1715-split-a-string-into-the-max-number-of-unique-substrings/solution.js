/**
 * @param {string} s
 * @return {number}
 */
var maxUniqueSplit = function (s) {
    const seen = new Set();

    const backtrack = (start) => {
        if (start === s.length) return seen.size;

        let maxSplits = 0;
        for (let i = start + 1; i <= s.length; i++) {
            const substring = s.slice(start, i);
            if (!seen.has(substring)) {
                seen.add(substring);
                maxSplits = Math.max(maxSplits, backtrack(i));
                seen.delete(substring);  // Backtrack
            }
        }
        return maxSplits;
    };

    return backtrack(0);
};
