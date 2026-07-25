class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        int n = numCourses;

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            graph[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // reachable[a][b] = true
        // means a is a prerequisite of b
        vector<vector<bool>> reachable(n, vector<bool>(n, false));

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neigh : graph[node]) {

                // node is a prerequisite of neigh
                reachable[node][neigh] = true;

                // Every prerequisite of node
                // is also a prerequisite of neigh
                for (int i = 0; i < n; i++) {
                    if (reachable[i][node]) {
                        reachable[i][neigh] = true;
                    }
                }

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        vector<bool> answer;

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            answer.push_back(reachable[a][b]);
        }

        return answer;
    }
};
