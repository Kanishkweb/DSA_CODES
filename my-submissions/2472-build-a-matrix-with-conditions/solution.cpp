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
            l[u].push_back(v); // directed edge u → v
        }
    };

    vector<int> topoSort(int V, vector<vector<int>> edges) {

        // Step 1: Create graph
        Graph g(V);
        for (auto& e : edges) {
            g.addEdge(e[0], e[1]);
        }

        // Step 2: Compute indegree
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (auto v : g.l[u]) {
                indegree[v]++;
            }
        }

        // Step 3: Push all nodes with indegree = 0
        queue<int> q;
        for (int i = 1; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: BFS
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto nbr : g.l[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if (topo.size() != V-1) {
            // cycle exists
            return {};
        }
        return topo;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        int n = rowConditions.size();
        int m = colConditions.size();
        vector<int> row = topoSort(k + 1, rowConditions);
        vector<int> col = topoSort(k + 1, colConditions);

        if(row.size() == 0 || col.size() == 0){
            // cycle exist in graph
            return {};
        }
        unordered_map<int, int> colmap;
        for (int i = 0; i < col.size(); i++) {
            int val = col[i];
            cout << val << endl;
            colmap[val] = i; // val -->index
        }
        // result vector
        vector<vector<int>> result(k, vector<int>(k, 0));
        // iterate the row
        for (int r = 0; r < row.size(); r++) {
            int val = row[r];
            int c = colmap[val];
            // fill the correct position to the result matrix;
            result[r][c] = val;
        }

        return result;
    }
};
