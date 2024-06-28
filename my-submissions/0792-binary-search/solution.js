/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let hi = nums.length - 1;
    let low = 0;
    while(low <= hi){
        let mid = low + Math.floor((hi - low)/2);
        // cheak if target less than mid or not 
        if(nums[mid] == target){
            return mid;
        }
        if(target > nums[mid]){
            // go right
            low = mid + 1;
        } else if (target < nums[mid]){
            // go left
            hi = mid - 1;
        }
    }
    return -1;
};
