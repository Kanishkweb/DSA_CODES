class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> result;
        // sorting in decending order;
        sort(nums.begin(), nums.end(), std::greater<int>());
        int i = 0;
        while (result.size() != k) {
            if(i == nums.size()) break;
            if (result.size() > 0) {
                if (result[result.size() - 1] != nums[i]) {
                    result.push_back(nums[i]);
                }
            } else if (result.size() == 0) {
                result.push_back(nums[i]);
            }
            i++;
        }
        return result;
    }
};
