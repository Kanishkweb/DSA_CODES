/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function lowerBound(arr, x) {
    let l = 0;
    let h = arr.length - 1;
    let ans;
    while (h >= l) {
        let mid = l + Math.floor((h - l) / 2);
        if (arr[mid] >= x) {
            // go for the left side
            ans = mid
            h = mid - 1
        } else {
            // go for the right side
            l = mid + 1
        }
    }
    if (arr[ans] == x) {
        return ans
    } else return -1


}

function upperBound(arr, x) {
    let l = 0;
    let h = arr.length - 1;
    let ans;
    while (h >= l) {
        let mid = l + Math.floor((h - l) / 2);
        if (arr[mid] <= x) {
            // go for the right side 
            l = mid + 1;
            ans = mid;
        } else {
            // go for the left side
            h = mid - 1
        }
    }
    if (arr[ans] == x) {
        return ans
    } else return -1
}
var searchRange = function (nums, target) {
    let a = lowerBound(nums, target);
    let b = upperBound(nums, target);
    return [a, b]
};
