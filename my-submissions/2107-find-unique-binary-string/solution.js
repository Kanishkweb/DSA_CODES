/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function (nums) {
    //    let ans = ""
    //    for (let i =0; i< nums.length; i++){
    //     ans += (nums[i][i] === '0' ? '1' : '0')
    //    }
    //    return ans

    let st = new Set()
    for (let num of nums) {
        st.add(parseInt(num, 2))
    }

    let n = nums.length
    let res =""
    for (let i =0; i<=n; i++){
if(!st.has(i)){
    res  = i.toString(2).padStart(16,'0')
    break;
}
    }
    return res.substring(16-n)
};
