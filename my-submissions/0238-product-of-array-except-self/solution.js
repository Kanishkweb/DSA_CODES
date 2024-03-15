/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    let product = 1;
    let answer = [];
    let zero = 0;
    // Calc the product;  Time:O(n)
    for (i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
            zero++
        } else {
            product *= nums[i];
        }
    }
    // divide each nums[i] from the product ans store it to the answer;
    // Time: O(n)
    for (i = 0; i < nums.length; i++) {
        let temp = product;
        //if zero is > 1 then all the result will be zero otherwise if zero == 1 then all the 
        // element which is zero calc store the product and in all the non zero element store the zero
        if (zero == 1) {
            if (nums[i] != 0) {
                answer.push(0)
            } else if (nums[i] == 0) {
                answer.push(temp)
            }
        } else if (zero > 1) {
            answer.push(0)
        } else {
            let op = temp / nums[i];
            answer.push(op);
        }
    }
    // Total Time: O(2n)
    return answer
};
