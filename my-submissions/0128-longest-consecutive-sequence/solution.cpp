class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        // average time - O(n);
        int maxLen = 0;
        for (int num : set) {
            if (set.find(num - 1) == set.end()) {
                // means its an good starting point
                int len = 0;
                while (set.find(num) != set.end()) {
                    len++;
                    num++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
