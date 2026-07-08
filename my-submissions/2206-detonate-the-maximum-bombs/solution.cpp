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
            l[a].push_back(b); // directed graph
        }

        void dfs(unordered_set<int>& visited, int node) {
            visited.insert(node);

            for (auto& currNode : l[node]) {
                if (visited.find(currNode) == visited.end()) {
                    dfs(visited, currNode);
                }
            }
        }
    };
    typedef long long LL;
    int maximumDetonation(vector<vector<int>>& bombs) {
        // valid range is too much secure
        int n = bombs.size();
        Graph g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                LL distance = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
                if (LL(r1*r1) >= distance) {
                    g.addEdge(i, j);
                }
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            g.dfs(visited, i);

            int count = visited.size();
            result = max(result, count);
        }
        return result;
    }
};
