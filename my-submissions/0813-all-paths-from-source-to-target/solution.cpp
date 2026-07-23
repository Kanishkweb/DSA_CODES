class Solution {
public:
    vector<vector<int>> result;
    int n;
    void dfs(vector<vector<int>>& graph,int node , vector<int>& temp,vector<bool>&visited) {
        visited[node] = true;
        temp.push_back(node);
        if(node == n-1){
            result.push_back(temp);
        }
        for(auto & currNode : graph[node]){
            if(!visited[currNode]){
                dfs(graph,currNode,temp,visited);
            }
        }
        // backtrack;
        temp.pop_back();
        visited[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        n = graph.size();
        vector<bool>visited(n);
        dfs(graph,0,temp,visited);
        return result;
    }
};
