class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if original value is zero
            if ((nums[i] == 0 && flip % 2 == 0) ||
                (nums[i]) == 1 && flip % 2 == 1) {
                // value is origianl
                flip++;
            }
        }
        return flip;
    }
};
