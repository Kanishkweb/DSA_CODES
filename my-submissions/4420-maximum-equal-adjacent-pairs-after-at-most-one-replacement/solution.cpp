class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>,int>mp;
        int basePair = 0;
        int maxPair = 0;
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                basePair++;
            } else {
                int a = min(nums[i],nums[i+1]);
                int b = max(nums[i],nums[i+1]);

                mp[{a,b}]++;
                int count = mp[{a,b}];
                if(count > maxPair){
                    maxPair = count;
                }
            }
        }
        return basePair + maxPair;
    }
};
