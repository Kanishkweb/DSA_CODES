class Solution {
public:
    int kadaneMin(vector<int> nums) {
        int minSum = INT_MAX;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            minSum = min(minSum, currSum);
            if (currSum > 0) {
                currSum = 0;
            }
        }
        return minSum;
    }
    int kadaneMax(vector<int> nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (auto& num : nums) {
            totalSum += num;
        }
        int kMax = kadaneMax(nums);
        int kMin = kadaneMin(nums);
        if (kMax > 0)
            return max(kMax,totalSum-kMin);
        else
            return kMax;
    }
};
