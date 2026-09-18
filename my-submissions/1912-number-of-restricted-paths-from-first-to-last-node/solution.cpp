class Graph {
public:
    int V;
    list<pair<int, int>>* l;
    int MOD = 1e9 + 7; // 1000000007
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int a, int b, int wt) {
        l[a].push_back({b, wt});
        l[b].push_back({a, wt});
    }

    int dfs(vector<bool>& visited, int node, vector<int>& temp,
            vector<int>& dp) {
        visited[node] = 1; // mark true
        if (node == V - 1) {
            return 1;
        }
        if (dp[node] != -1)
            return dp[node];
        int ans = 0;
        for (auto& neigh : l[node]) {
            int currNode = neigh.first;

            if (temp[node] > temp[currNode]) {
                ans = (ans + dfs(visited, currNode, temp, dp)) % MOD;
            }
        }
        // undo
        visited[node] = 0; // mark false;
        return dp[node] = ans;
    }
    vector<int> dijkstra(int src) {
        // distance array
        vector<int> dist(V, INT_MAX);

        // min heap -> (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // init
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int currDist = top.first;
            int node = top.second;

            // skip outdated entries
            if (currDist > dist[node])
                continue;

            // traverse neighbors
            for (auto nbr : l[node]) {
                int neigh = nbr.first;
                int weight = nbr.second;

                if (dist[node] + weight < dist[neigh]) {
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist;
    }
};

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        Graph g(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int wt = edges[i][2];

            g.addEdge(a, b, wt);
        }

        vector<int> temp = g.dijkstra(n);
        // dfs
        vector<bool> visited(n + 1);
        // start from 1 -- > n
        vector<int> dp(n + 1, -1);
        return g.dfs(visited, 1, temp, dp);
    }
};
