class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

        for (auto &e : relations) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> finishTime(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                finishTime[i] = time[i - 1];
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                finishTime[neigh] = max(finishTime[neigh],
                                        finishTime[node] + time[neigh - 1]);

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, finishTime[i]);
        }

        return ans;
    }
};
