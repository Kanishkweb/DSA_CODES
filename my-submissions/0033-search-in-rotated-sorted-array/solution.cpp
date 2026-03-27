class Solution {
public:
    int search(vector<int>& nums, int target) {
        // write the template code for the binary search
        int start= 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            // now take the decision for the search space
            // check whether the left half is sorted
            if(nums[start] <= nums[mid]){
                // means left half is sorted
                if(nums[mid] == target) return mid;
                if(nums[start] <= target && target < nums[mid]){
                    end = mid-1;
                } else{
                    start = mid+1;
                }
            } else{
                // means right half is sorted
                if(nums[mid] == target) return mid;
                if(nums[mid] < target && target <= nums[end]){
                    start = mid+1;
                } else {
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};
