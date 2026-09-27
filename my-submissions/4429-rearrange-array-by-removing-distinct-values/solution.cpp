class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto & num : nums){
            mp[num]++;
        }
        vector<int>ans;
        while(n > 0){
            vector<int>temp;
            for(auto & op : mp){
                if(op.second > 0){
                    temp.push_back(op.first);
                    mp[op.first]--;
                    n--;
                }
            }
            sort(temp.begin(),temp.end());
            for(auto arr : temp){
                ans.push_back(arr);
            }
        }
        return ans;
    }
};
