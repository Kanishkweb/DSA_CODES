class Solution {
public:
    class Graph {
        int V;
        list<int>* l;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int a, int b) {
            l[a].push_back(b); // directed edge
        }

        bool dfs(int currNode, vector<bool>& visited, vector<bool>& recPath) {
            visited[currNode] = 1; // mark true
            recPath[currNode] = 1; // mark true

            for (int& node : l[currNode]) {
                if (!visited[node]) {
                    if (!dfs(node, visited, recPath)) {
                        return false;
                    }
                } else if (recPath[node]) {
                    return 0; // false cycle exist
                }
            }

            // backtrack
            recPath[currNode] = 0; // mark false
            return true;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        Graph g(V);
        // now add all the edges of the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g.addEdge(a, b);
        }
        vector<bool> visited(V);
        vector<bool> recPath(V);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (!g.dfs(i, visited, recPath)) {
                    return 0; // false
                }
            }
        }
        return 1; // true
    }
};
