class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& graph,
             vector<int>& ans, int node) {
        visited[node] = true;
        // visit all the neighbour
        for (auto& currNode : graph[node]) {
            if (!visited[currNode]) {
                ans.push_back(currNode);
                dfs(visited, graph, ans, currNode);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // we need to create the graph;
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[b].push_back(a);
        }

        // do dfs of every node;
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n);
            vector<int> ans;
            dfs(visited, graph, ans, i);
            result.push_back(ans);
        }

        // sort all the ans arr
        for (int i = 0; i < result.size(); i++) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};
