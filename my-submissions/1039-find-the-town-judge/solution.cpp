class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        for(int i = 0;i<trust.size();i++){
            int out = trust[i][0];
            int in = trust[i][1];
            indegree[out] = -1;
            if(indegree[in] != -1){
                indegree[in]++;
            }
        }
        for(int i = 1;i<=n;i++){
            if(indegree[i] == n-1) return i;
        }
        return -1;
    }
};
