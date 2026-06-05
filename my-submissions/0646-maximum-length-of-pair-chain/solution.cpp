class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 1; // one will always the ans for setting default cause one 
        // will always there a pair

        // sorting
        sort(pairs.begin(),pairs.end(),[](auto & a,auto & b){
            return a[1] < b[1];
        });

        // main logic
        int lastEle = pairs[0][1];
        for(int i = 1;i<pairs.size();i++){
            // check for non overlapping;
            int currFirstEle = pairs[i][0];
            int currLastEle = pairs[i][1];
            if(lastEle < currFirstEle){
                ans++;
                lastEle = currLastEle;
            }
        }
        return ans;
    }
};
