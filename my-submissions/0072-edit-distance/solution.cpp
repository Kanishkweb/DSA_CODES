class Solution {
public:
    int solve(string &word1, string &word2 , int i,int j,vector<vector<int>>&dp){
        int m = word1.length();
        int n = word2.length();
        if(j >= n){
            return m-i;
        }
        if(i >= m){
            return n-j;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return solve(word1, word2 , i+1,j+1,dp);
        }
        int insert = 1 + solve(word1,word2,i,j+1,dp);
        int replace = 1 + solve(word1,word2,i+1,j+1,dp);
        int del = 1 + solve(word1,word2,i+1,j,dp);

        dp[i][j] = min(insert,min(replace,del));
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};
