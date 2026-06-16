class Solution {
public:
    int dp[601][101][101];
    pair<int,int> checkBC(string &s){
        // check function
        int m = 0;
        int n = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0'){
                m++;
            } else{
                n++;
            }
        }
        return {m,n};
    }

    int solve(vector<string>&strs,int idx ,int m, int n){
        // base case
        if(idx >= strs.size()) return 0;
        if(m < 0 || n < 0) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        auto pr = checkBC(strs[idx]);
        int zero = pr.first;
        int one = pr.second;
        int take = INT_MIN;
        if(m-zero >= 0 && n-one >= 0){
            take = 1 + solve(strs,idx+1,m-zero,n-one);
        }
        int skip = solve(strs,idx+1,m,n);

        return dp[idx][m][n] = max(take,skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);
        return 0;
    }
};
