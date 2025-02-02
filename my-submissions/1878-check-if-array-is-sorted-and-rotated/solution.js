/**
 * @param {number[]} nums
 * @return {boolean}
 */
/**
 * @param {number[]} nums
  * @return {boolean}
   */
   var check = function (nums) {
       let countBreaks = 0;
           let n = nums.length;
           
               for (let i = 0; i < n; i++) {
                       if (nums[i] > nums[(i + 1) % n]) {
                                   countBreaks++;
                                           }
                                                   if (countBreaks > 1) return false; // More than one drop
                                                       }
                                                       
                                                           return true;
                                                           }; 
    

