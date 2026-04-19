class Solution {
public:
    class Graph {
    public:
        int V;
        list<int>* l;

        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int u, int v) {
            l[u].push_back(v); // u → v
        }

        void dfs(int node, vector<bool>& visited, stack<int>& st) {
            visited[node] = true;

            for (auto nbr : l[node]) {
                if (!visited[nbr]) {
                    dfs(nbr, visited, st);
                }
            }

            st.push(node); // important step
        }
    };

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        Graph g(n);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            g.addEdge(a, b);
        }

        stack<int> st;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                g.dfs(i, visited, st);
            }
        }
        vector<int> order;
        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        vector<set<int>> result(n);
        // main logic
        for (int i = 0; i < n; i++) {
            int node = order[i];
            for (auto & neigh : g.l[node]) {
                result[neigh].insert(node);
                result[neigh].insert(result[node].begin(), result[node].end());
            }
        }
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(result[i].begin(), result[i].end());
        }
        return ans;
    }
};
