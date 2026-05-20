class Solution {
public:
    int rob(vector<int>& nums) {
        // edge case
        int n = nums.size();
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        } else if(nums.size() == 1){
            return nums[0];
        }

        nums[2] = nums[2] + nums[0];
        for(int i = 3;i<n;i++){
            nums[i] = nums[i] + max(nums[i-2],nums[i-3]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};
