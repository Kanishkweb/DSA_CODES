/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function(matrix) {
    let absSum = 0;       // Total sum of absolute values
    let negCount = 0;     // Count of negative numbers
    let absMin = Infinity; // Minimum absolute value in the matrix

    for (const row of matrix) {
        for (const num of row) {
            absSum += Math.abs(num);          // Add absolute value to total sum
            absMin = Math.min(absMin, Math.abs(num)); // Track the smallest absolute value
            if (num < 0) negCount++;          // Count negatives
        }
    }

    // If negative count is odd, subtract twice the smallest absolute value
    return (negCount % 2 === 1) ? absSum - 2 * absMin : absSum;
};
