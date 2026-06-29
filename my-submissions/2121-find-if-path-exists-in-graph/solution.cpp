class Solution {
public:
    class Graph {
    private:
        list<int>* l;
        int V;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int a, int b) {
            l[a].push_back(b);
            l[b].push_back(a);
        }
        bool dfs(vector<bool>& visited, int currNode, int dest) {
            visited[currNode] = true;

            for (auto& node : l[currNode]) {
                if (!visited[node]) {
                    if (node == dest) return true;
                    if (dfs(visited, node, dest)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination)
            return true;
        Graph g(n); // n is no of vertices

        // adding all the edges of graph
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            g.addEdge(a, b);
        }
        vector<bool> visited(n);
        bool ans = g.dfs(visited, source, destination);
        return ans;
    }
};
