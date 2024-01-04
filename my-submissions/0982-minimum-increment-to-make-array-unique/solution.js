/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function (nums) {
    function merge(left, right) {
        let result = [];
        let leftIndex = 0;
        let rightIndex = 0;

        while (leftIndex < left.length && rightIndex < right.length) {
            if (left[leftIndex] <= right[rightIndex]) {
                result.push(left[leftIndex]);
                leftIndex++;
            } else {
                result.push(right[rightIndex]);
                rightIndex++;
            }
        }

        return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
    }

    function mergeSort(nums) {
        if (nums.length <= 1) {
            return nums;
        }

        const middle = Math.floor(nums.length / 2);
        const left = nums.slice(0, middle);
        const right = nums.slice(middle);

        return merge(mergeSort(left), mergeSort(right));
    }

    nums = mergeSort(nums);

    let c = [];
    let count = 0;
    // storing first value to the c array;
    c.push(nums[0]);
    // first loop for iterating on the nums array;
    for (i = 1; i < nums.length; i++) {
        let last = c.length - 1;
        if (c[last] < nums[i]) {
            c.push(nums[i]);
        } else {
            while (c[last] >= nums[i]) {
                nums[i]++;
                count++;
            }
            c.push(nums[i]);
        }
    }
    return count;
};

