/**
 * @param {number} k
 * @param {number[]} nums
 */

let K;
let result;
var KthLargest = function (k, nums) {
    // k is the kth largest element we need to print all the time;
    // nums is the stream where we can be able to append the elements and return 
    K = k;
    result = [...nums];
};

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function (val) {
    result.push(val);
    result.sort((a, b) => {
        return b - a;
    })
    while (result.length > K) result.pop();
    return result[K-1];
};

/** 
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
