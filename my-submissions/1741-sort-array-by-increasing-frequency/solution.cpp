class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // count frequency
        unordered_map<int,int>freq;
        for(auto& num:nums){
            freq[num]++;
        }
        // create buckets
        int n = nums.size();
        vector<vector<int>>buckets(n+1);

        for(auto&[num,count]:freq){
            buckets[count].push_back(num);
        }
        // build result
        vector<int>result;
        for(int freq = 1;freq<=n;freq++){
            if(buckets[freq].size() == 0) continue;

            // sort the number with same frequency
            sort(buckets[freq].begin(),buckets[freq].end(),greater<int>());

            for(int num : buckets[freq]){
                for(int i = 0;i<freq;i++){
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};
