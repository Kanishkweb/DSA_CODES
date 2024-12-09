/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */

var minimumSize = function (nums, maxOperations) {
    // we will apply binary search
    let r = 1; // r always start with 1
    let l = 0; // for only for the initialization
    let ans = Infinity; // for storing our minimum ans;
    for (let i = 0; i < nums.length; i++) {
        l = Math.max(l, nums[i]);
    }

    while (r <= l) {
        let mid = Math.floor((r + l) / 2);
        if (checkAns(nums, maxOperations, mid)) {
            ans = Math.min(ans, mid);
            l = mid - 1;
        } else {
            r = mid + 1;
        }
    }
    return ans;
};

function checkAns(nums, maxOperations, mid) {
    let currOp = 0;
    for (let num of nums) {
        if (num == mid) continue;
        let temp = Math.floor(num / mid);
        if (num % mid == 0) {
            temp -= 1;
        }
        currOp += temp;
    }
    if (maxOperations >= currOp) {
        return true;
    } else {
        false;
    }
}


