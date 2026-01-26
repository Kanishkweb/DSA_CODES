class Solution {
public:
    unordered_map<string, int> mp;
    class Graph {
        int V;
        list<pair<string, double>>* l;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<pair<string, double>>[V];
        }

        void addEdge(string a, string b, double val,
                     unordered_map<string, int>& mp) {
            int idxA = mp[a] - 1;
            int idxB = mp[b] - 1;
            l[idxA].push_back({b, val});
            l[idxB].push_back({a, 1.0 / val});
        }

        bool dfs(string currNode, string b, unordered_map<string, int>& mp,
                 vector<bool>& visited, double& product) {
            if (mp.find(currNode) == mp.end()) {
                return false;
            }
            int idx = mp[currNode] - 1;
            visited[idx] = 1; // true;

            for (auto& node : l[idx]) {
                int idxN = mp[node.first] - 1;
                double prev = product;
                product *= node.second;
                if (node.first == b) {
                    // product *= node.second;
                    return true;
                }
                if (!visited[idxN]) {
                    if (dfs(node.first, b, mp, visited, product)) {
                        return true;
                    }
                }
                product = prev;
            }
            return false;
        }
    };
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int V = 0;
        int index = 1;
        for (int i = 0; i < equations.size(); i++) {
            for (string& node : equations[i]) {
                if (mp.find(node) == mp.end()) {
                    mp[node] = index;
                    index++;
                    V++;
                }
            }
        }

        Graph g(V);
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            g.addEdge(a, b, val, mp);
        }

        // now this code only need traversal
        vector<double> result;
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            double product = 1.0;
            vector<bool> visited(V, false);
            if (g.dfs(a, b, mp, visited, product)) {

                result.push_back(product);
            } else {
                result.push_back(-1.0);
            }
        }
        return result;
    }
};
