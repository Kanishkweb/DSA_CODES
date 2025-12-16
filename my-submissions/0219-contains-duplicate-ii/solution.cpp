class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            if(seen.find(num) != seen.end() && abs(i - seen[num]) <= k){
                return true;
            }
            seen[num] = i;
        }
        return false;
    }
};
