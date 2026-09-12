class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        if(n == 1) return {0};
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            indegree[a]++;
            indegree[b]++;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }


        while (n > 2) {
            int size = q.size();
            n -= size;

            while (size--) {
                int node = q.front();
                q.pop();

                for (int neigh : graph[node]) {

                    indegree[neigh]--;

                    if (indegree[neigh] == 1) {
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
