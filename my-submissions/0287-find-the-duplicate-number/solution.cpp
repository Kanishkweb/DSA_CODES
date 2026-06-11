class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        int r = nums[0];
        t = nums[t];
        r = nums[nums[r]];
        while (t != r) {
            t = nums[t];
            r = nums[nums[r]];
        }
        t = nums[0];
        while (t != r) {
            t = nums[t];
            r = nums[r];
        }
        return t;
    }
};
