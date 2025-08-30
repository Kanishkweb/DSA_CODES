class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<k-1;i++){
            pop_heap(nums.begin(),nums.begin() + n);
            n--;
        }
        return nums[0]; // front
    }
};
