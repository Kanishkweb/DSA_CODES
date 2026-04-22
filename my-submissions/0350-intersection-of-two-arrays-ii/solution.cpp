class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto & num:nums1){
            mp[num]++;
        }
        vector<int>result;
        for(int i = 0;i<nums2.size();i++){
            if(mp.find(nums2[i]) != mp.end() && mp[nums2[i]] > 0){
                result.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return result;
    }
};
