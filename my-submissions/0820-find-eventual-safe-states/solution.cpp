class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> graphR(n);
        for (int i = 0; i < n; i++) {
            for (auto& node : graph[i]) {
                graphR[node].push_back(i);
            }
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graphR[i].size(); j++) {
                int a = graphR[i][j];
                indegree[a]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i); // push all the indegree with zero;
            }
        }
        // vector<bool> visited(n);
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            // visit all the directed edge
            for (int i = 0; i < graphR[node].size(); i++) {
                int currNode = graphR[node][i];

                    indegree[currNode]--;
                    if (indegree[currNode] == 0) {
                        q.push(currNode);
                    }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
