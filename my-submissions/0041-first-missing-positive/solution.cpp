class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // check if one present in the array or not
        int n = nums.size();
        bool checkOne = false;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1) checkOne = true;
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        // edge case
        if(!checkOne) return 1;
        // making the no negative
        for(int i = 0;i<n;i++){
            int idx = abs(nums[i]) -1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }

        // now check for the ans
        for(int i = 0;i<n;i++){
            if(nums[i] > 0){
                // means positive
                return i + 1;
            }
        }
        return n+1;
    }
};
