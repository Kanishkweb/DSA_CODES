class Solution {
public:
    int solve(string &word1, string &word2, int i, int j,
              vector<vector<int>>& dp) {
        int m = word1.length();
        int n = word2.length();

        if(i >= m) return n-j;
        if(j >= n) return m-i; // store the result

        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1,word2,i+1,j+1,dp);
        int insert = 1 + solve(word1,word2,i,j+1,dp);
        int del = 1 + solve(word1,word2,i+1,j,dp);
        int replace = 1 + solve( word1, word2,i+1,j+1,dp);

        dp[i][j] = min(insert,min(del,replace));
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
