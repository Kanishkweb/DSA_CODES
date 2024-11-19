/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function (nums, k) {
    let freq = {};
    let sum = 0;
    let maxSum = 0;
    let distinctCount = 0;

    for (let i = 0; i < nums.length; i++) {
        let currVal = nums[i];
        sum += currVal;

        // Update the frequency map and distinct count
        if (!freq[currVal]) {
            freq[currVal] = 1;
            distinctCount++; // New distinct element added
        } else {
            freq[currVal]++;
        }

        // If the window size exceeds k, remove the leftmost element
        if (i >= k) {
            let leftVal = nums[i - k];
            sum -= leftVal;
            freq[leftVal]--;

            if (freq[leftVal] === 0) {
                delete freq[leftVal]; // Clean up the map
                distinctCount--; // One distinct element removed
            }
        }

        // Check if the subarray of size k is valid
        if (i >= k - 1 && distinctCount === k) {
            maxSum = Math.max(maxSum, sum);
        }
    }

    return maxSum;
};

