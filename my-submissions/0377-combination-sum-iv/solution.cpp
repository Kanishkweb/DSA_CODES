class Solution {
public:
    int n;
    int dp[10001];
    int solve(vector<int>&nums,int target){
        // base case 
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target]!= -1) return dp[target];
        // main logic
        int ans = 0;
        for(int idx = 0;idx<n;idx++){
            ans += solve(nums,target-nums[idx]);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);
    }
};
