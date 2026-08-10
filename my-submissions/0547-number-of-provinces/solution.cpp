class Solution {
public:
    void dfs(vector<bool>&visited,int node, vector<vector<int>>&isConnected){
        visited[node] = true;

        // visit all the neighbours
        for(int i = 0;i<isConnected.size();i++){
            if(node == i) continue;
            int check = isConnected[node][i];
            if(check && !visited[i]){
                dfs(visited,i,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool>visited(n);
        int count = 0;
        for(int node = 0;node<n;node++){
            // check dfs for all the nodes which are not visited
            if(!visited[node]){
                count++;
                dfs(visited,node,isConnected);
            }
        }
        return count;
    }
};
