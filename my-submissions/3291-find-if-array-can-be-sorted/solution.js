/**
 * @param {number[]} nums
 * @return {boolean}
 */


var canSortArray = function (nums) {
    // function is to print the no of set bit and its binary represntation
    let obj = {};
    for (let i = 0; i < nums.length; i++) {
        let temp = nums[i].toString(2); // This is an by default method to convert no to binary no in the javaScript Language.
        obj[nums[i]] = temp.split("1").length - 1;
    }
    // main sorting
    for (let i = 0; i < nums.length - 1; i++) {
        // first check if adjacent element want to sort or not
        while (nums[i] > nums[i + 1]) {
            // need to swap
            if (obj[nums[i]] != obj[nums[i + 1]]) {
                return false;
            } else {
                swap(i, i + 1,nums); // cause we can only swap adjacent element
                i--;
            }
        }
    }

    // now check if the array got sorted or not
    let arr = [...nums];
    arr.sort((a, b) => {
        return a - b;
    });
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != arr[i]) {
            return false;
        }
    }
    return true;
};
function swap(a, b, nums) {
    let temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
