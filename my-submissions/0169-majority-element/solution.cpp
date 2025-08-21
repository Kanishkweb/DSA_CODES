class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int candidate = 0;

        for (auto num : nums) {
            if (freq == 0) {
                candidate = num;
            }
            if (num == candidate) {
                freq++;
            } else {
                freq--;
            }
        }
        return candidate; // Moore voting algo
    }
};
