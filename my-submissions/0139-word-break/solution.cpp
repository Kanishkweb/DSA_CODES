class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>dict;
        for(auto & word : wordDict){
            dict.insert(word);
        }
        vector<bool>dp(n+1,0);

        dp[n] = 1; // empty string always true;

        for(int i = n-1;i>=0;i--){
            for(int l = 1;l<=n-i;l++){
                string temp = s.substr(i,l);
                if(dict.find(temp) != dict.end() && dp[i+l]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
