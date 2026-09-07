class Solution {
public:
    void dfs(int node, vector<bool>&visited,vector<vector<int>>&isConnected){
        visited[node] = true;

        for(int i = 0;i<isConnected.size();i++){
            if(isConnected[node][i] == 0) continue;
            if(!visited[i]){
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool>visited(n);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};
