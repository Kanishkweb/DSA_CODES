class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachMax = 0;
        for(int i = 0;i<nums.size();i++){
            if(reachMax < i) {
                return false;
            } else{
                reachMax = max(reachMax,i + nums[i]);
            }
        }
        return true;
    }
};
