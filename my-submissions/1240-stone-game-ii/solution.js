/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function (piles) {
    const totalPiles = piles.length;
    const suffixSums = new Array(totalPiles + 1).fill(0);
    for (let i = totalPiles - 1; i >= 0; i--) {
        suffixSums[i] = suffixSums[i + 1] + piles[i];
    }

    const memo = Array.from({ length: totalPiles }, () => new Array(totalPiles + 1).fill(0));

    const maxStonesAliceCanGet = (m, currentPile) => {
        if (currentPile >= totalPiles) return 0;

        if (currentPile + 2 * m >= totalPiles) {
            return suffixSums[currentPile];
        }

        if (memo[currentPile][m] !== 0) return memo[currentPile][m];

        let maxStones = 0;

        for (let x = 1; x <= 2 * m; x++) {
            const currentStones = suffixSums[currentPile] - maxStonesAliceCanGet(Math.max(m, x), currentPile + x);
            maxStones = Math.max(maxStones, currentStones);
        }

        memo[currentPile][m] = maxStones;
        return maxStones;
    };

    return maxStonesAliceCanGet(1, 0);
};
