class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        // add all the edges
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            indegree[a]++;
            adj[b].push_back(a); // directed edge;
        }
        // now the main logic of toposort
        queue<int> q;
        // push 0 indegree ele in the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        // now the legacy bfs code
        while (!q.empty()) {
            int node = q.front();
            q.pop(); // front will pop from the queue;
                     // push all the neighbours of the queue
            topo.push_back(node);
            for (auto nbr : adj[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if (topo.size() != V) {
            return false;
        }
        return true;
    }
};
