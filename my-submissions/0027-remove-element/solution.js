/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let n = nums.length;
    let temp = [];
    let k = 0;  //  number of elements in nums which are not equal to val
    // traverse the nums first;
    for (let i = 0; i < n; i++) {
        if (nums[i] == val) {
            // we need to remove this element 

        } else {
            k++;
            // this will store the val which is not equal to val;
            temp.push(nums[i]);
        }
    }

    // now pass the val into the original array;;
    for(let i = 0;i<temp.length;i++){
        nums[i] = temp[i];
    }

    return k;
};
