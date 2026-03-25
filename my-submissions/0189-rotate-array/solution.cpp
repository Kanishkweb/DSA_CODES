class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // step 1 - reverse the whole array
        reverse(nums.begin(),nums.end());
        // step 2 - reverse first k elements
        reverse(nums.begin(),nums.begin()+k);
        // step 3 - reverse remaining elements
        reverse(nums.begin()+k,nums.end());
    }
};
