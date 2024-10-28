/**
 * @param {number[]} nums
 * @return {number}
 */
function longestSquareStreak(nums) {
    const mp = new Map();
    nums.sort((a, b) => a - b);
    let res = -1;

    for (const num of nums) {
        const sqrt = Math.floor(Math.sqrt(num));

        if (sqrt * sqrt === num && mp.has(sqrt)) {
            mp.set(num, mp.get(sqrt) + 1);
            res = Math.max(res, mp.get(num));
        } else {
            mp.set(num, 1);
        }
    }

    return res;
}
