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
            l[a].push_back(b); // directed edge;
        }

        vector<int> topoSort(vector<int>& indegree) {
            vector<int> topo;
            queue<int> q;
            // nodes with zero indegree push into queue
            for (int i = 1; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int node = q.front();
                topo.push_back(node);
                q.pop();
                // visit all the neighbours
                for (auto& currNode : l[node]) {
                    indegree[currNode]--;
                    if (indegree[currNode] == 0) {
                        q.push(currNode);
                    }
                }
            }
            return topo;
        }
    };

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        
        Graph g(k+1);

        // addEdges to the graph
        vector<int> indegree(k+1, 0);
        for (int i = 0; i < rowConditions.size(); i++) {
            int a = rowConditions[i][0];
            int b = rowConditions[i][1];
            indegree[b]++;
            g.addEdge(a, b);
        }
        // perform a topo sort;
        vector<int> topoRow = g.topoSort(indegree);
        // cycle exists
        if (topoRow.size() != k) {
            return {};
        }
        Graph h(k+1);

        // addEdges to the graph
        indegree.assign(k+1, 0);
        for (int i = 0; i < colConditions.size(); i++) {
            int a = colConditions[i][0];
            int b = colConditions[i][1];
            indegree[b]++;
            h.addEdge(a, b);
        }
        vector<int> topoCol = h.topoSort(indegree);
        // cycle exists
        if (topoCol.size() != k) {
            return {};
        }
        // for search operation in O(1) // we will make map;
        unordered_map<int, int> mp;
        for (int i = 0; i < topoCol.size(); i++) {
            int node = topoCol[i];
            mp[node] = i; // store node->idx;
        }
        // now the main logic build the matrix;
        vector<vector<int>> result(k,
                                   vector<int>(k, 0)); // k*k filled with zero;
        for (int i = 0; i < topoRow.size(); i++) {
            int node = topoRow[i];
            int idxCol = mp[node];
            result[i][idxCol] = node;
        }
        return result;
    }
};
