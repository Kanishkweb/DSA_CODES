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
            l[a].push_back(b); // directed node
        }
        bool checkCycle(int currNode, vector<bool>& visited,
                        vector<bool>& recPath,vector<int>&result) {
            visited[currNode] = 1; // true
            recPath[currNode] = 1; // true

            for (int& node : l[currNode]) {
                if (!visited[node]) {
                    if (!checkCycle(node, visited, recPath,result)) {
                        return false;
                    }
                } else if (recPath[node]) {
                    return false;
                }
            }
            // backtrack
            result.push_back(currNode);
            recPath[currNode] = 0; // false
            return true;
        }
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        Graph g(V);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g.addEdge(a, b);
        }
        // first we will check if cycle exist
        vector<bool> visited(V);
        vector<bool> recPath(V);
        stack<int> st;
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (!g.checkCycle(i, visited, recPath,result)) {
                    return {}; // pass empty vector
                }
            }
        }
        return result;
    }
};
