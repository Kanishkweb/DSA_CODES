class Graph {
public:
    int V;
    list<pair<int, int>>* l;

    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int a, int b, int wt) { l[a].push_back({b, wt}); }

    vector<int> dijkstra(int src) {
        // distance array
        vector<int> dist(V, INT_MAX);

        // min heap // (distance,node)
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

            // skip outdated entries;
            if (currDist > dist[node])
                continue;

            // traverse neighbours
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n + 1);

        // addEdge
        for (int i = 0; i < times.size(); i++) {
            int a = times[i][0];
            int b = times[i][1];
            int wt = times[i][2];
            g.addEdge(a, b, wt);
        }

        vector<int> op = g.dijkstra(k);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (op[i] == INT_MAX)
                return -1;
            ans = max(ans, op[i]);
        }

        return ans;
    }
};
