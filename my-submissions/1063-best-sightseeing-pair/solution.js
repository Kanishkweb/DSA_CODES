/**
 * @param {number[]} values
 * @return {number}
 */
var maxScoreSightseeingPair = function(values) {
    const n = values.length;
    const leftMax = Array(n).fill(0);
    const rightMax = Array(n).fill(0);

    // Compute leftMax array
    leftMax[0] = values[0];
    for (let i = 1; i < n; i++) {
        leftMax[i] = Math.max(leftMax[i - 1], values[i] + i);
    }

    // Compute rightMax array
    rightMax[n - 1] = values[n - 1] - (n - 1);
    for (let i = n - 2; i >= 0; i--) {
        rightMax[i] = Math.max(rightMax[i + 1], values[i] - i);
    }

    // Compute the maximum score
    let maxi = 0;
    for (let i = 1; i < n; i++) {
        maxi = Math.max(maxi, leftMax[i - 1] + rightMax[i]);
    }

    return maxi;
};
