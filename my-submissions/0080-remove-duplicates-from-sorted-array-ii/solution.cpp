class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // ans of size n
        int op = nums[0];
        int freq = 0;
        int size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq < 2 && nums[i] == op) {
                freq++;
            } else if (nums[i] == op) {
                continue;
            } else {
                op = nums[i];
                freq = 1;
            }
            ans[size] = op;
            size++;
        }
        nums = ans;
        return size;
    }
};
