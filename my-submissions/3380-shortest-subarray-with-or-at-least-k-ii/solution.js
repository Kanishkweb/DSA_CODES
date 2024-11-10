/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function minimumSubarrayLength(nums, k) {
    const count = Array(32).fill(0);
    let start = 0, minLength = nums.length + 1;

    for (let end = 0; end < nums.length; end++) {
        updateBits(count, nums[end], 1);

        while (start <= end && getVal(count) >= k) {
            minLength = Math.min(minLength, end - start + 1);
            updateBits(count, nums[start], -1);
            start++;
        }
    }
    return minLength === nums.length + 1 ? -1 : minLength;
}

function updateBits(count, num, val) {
    for (let i = 0; i < 32; i++) {
        if ((num & (1 << i)) !== 0) {
            count[i] += val;
        }
    }
}

function getVal(count) {
    let ans = 0;
    for (let i = 0; i < 32; i++) {
        if (count[i] > 0) {
            ans |= (1 << i);
        }
    }
    return ans;
}
