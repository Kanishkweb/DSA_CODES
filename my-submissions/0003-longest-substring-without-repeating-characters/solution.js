/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let mp = {};
    let st = 0, en = 0;
    let ans = 0;
    while(en < s.length) {
        if(!mp[s[en]]) {
            mp[s[en]] = 1;
        } else [
            mp[s[en]]++
        ]
        while(mp[s[en]] > 1){
            mp[s[st]]--;
            st++;
        }
        ans = Math.max(ans,en - st +1);
        en++;
    }
    return ans
};
