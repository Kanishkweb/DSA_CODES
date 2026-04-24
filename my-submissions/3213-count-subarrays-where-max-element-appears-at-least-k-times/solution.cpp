class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        int maxEle = INT_MIN;
        int n = nums.size();
        for (auto& num : nums) {
            maxEle = max(maxEle, num);
        }
        while (j < n) {
            if (nums[j] == maxEle)
                count++;

            while (count >= k) {
                result += n - j;
                if (nums[i] == maxEle)
                    count--;
                i++;
            }
            j++;
        }
        return result;
    }
};
