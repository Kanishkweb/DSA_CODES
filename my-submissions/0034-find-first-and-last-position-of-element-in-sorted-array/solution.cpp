class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int start = 0;
        int end = nums.size() - 1;
        int idx = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                idx = mid;
                break;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (idx >= 0) {
            while (idx >= 0 && nums[idx] == target) {
                idx--;
            }
            start = idx+1;
            idx = start;
            while(idx <= nums.size()-1  && nums[idx] == target){
                idx++;
            }
            end = idx-1;
        } else{
            start = -1;
            end = -1;
        }
        vector<int>result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};
