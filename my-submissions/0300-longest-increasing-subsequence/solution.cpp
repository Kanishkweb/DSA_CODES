class Solution {
public:
    int binarySearch(vector<int>& result, int target) {
        int start = 0;
        int end = result.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (result[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (result[result.size() - 1] < nums[i]) {
                result.push_back(nums[i]);
            } else {
                int position = binarySearch(result, nums[i]);
                result[position] = nums[i];
            }
        }
        return result.size();
    }
};
