class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int a = 0;
        int b = 0;
        int minLen = INT_MAX;
        int currSum = 0;
        while (nums.size() > b) {
            currSum += nums[b];
            b++;
            while (target <= currSum) {
                minLen = min(minLen, b - a);
                currSum = currSum - nums[a];
                a++;
            }
        }
        if (minLen == INT_MAX)
            return 0;
        return minLen;
    }
};
