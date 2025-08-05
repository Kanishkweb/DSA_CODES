class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                k++;
                temp.push_back(nums[i]);
            }
        }
        // now paste the element into the original nums;
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        return k;
    }
};
