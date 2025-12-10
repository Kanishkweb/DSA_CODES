class Solution {
public:
    int kadaneMax(vector<int>& nums) {
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
    int kadaneMin(vector<int>& nums) {
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

    int maxSubarraySumCircular(vector<int>& nums) {
        // 1
        int SUM = accumulate(begin(nums),end(nums),0);

        // 2
        int minSum = kadaneMin(nums);

        //3
        int maxSum = kadaneMax(nums);

        //4
        int circular_sum = SUM - minSum;

        if(maxSum > 0){
            return max(maxSum,circular_sum);
        }

        return maxSum;
    }
};
