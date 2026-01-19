class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int zero = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (!(nums[j] & (1 << i))) {
                    zero++;
                }
            }
            if (zero % 3 == 0) {
                result = result | (1 << i);
            }
        }
        return result;
    }
};
