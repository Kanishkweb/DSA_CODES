class Solution {
public:
    void solve(vector<int>&nums,int idx,vector<vector<int>>&result){
        // base case 
        if(idx == nums.size()-1){
            result.push_back(nums);
        }
        // main logic of the code
        for(int i = idx;i<nums.size();i++){
            // swap the array with the i and idx
            swap(nums[i],nums[idx]);
            solve(nums,idx+1,result);
            // backtrack
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // approach swap to calc all the permutation
        vector<vector<int>>result;
        int idx = 0;
        solve(nums,idx,result);
        return result;
    }
};
