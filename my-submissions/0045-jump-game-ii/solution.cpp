class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int reachMax = 0;
        int lastIdx = nums.size() - 1;
        int count = 0;
        int stIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            reachMax = max(reachMax, i + nums[i]);
            if(stIdx <= i){
                count++;
                stIdx = reachMax;
                if(stIdx >= lastIdx) break;
            }
        }
        return count;
    }
};
