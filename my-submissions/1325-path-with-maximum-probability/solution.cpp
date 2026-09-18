class Graph {
public:
    int V;
    list<pair<int, double>>* l;

    Graph(int V) {
        this->V = V;
        l = new list<pair<int, double>>[V];
    }
    void addEdge(int a, int b, double wt) {
        l[a].push_back({b, wt});
        l[b].push_back({a, wt});
    }

    vector<double> dijkstra(int src) {
        // distance array
        vector<double> dist(V, -1e18);

        // max heap -> (distance, node)
        priority_queue<pair<double, int>> pq;

        // init
        dist[src] = 0.0;
        pq.push({0.0, src});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            double currDist = top.first;
            int node = top.second;

            // skip outdated entries
            if (currDist < dist[node])
                continue;

            // traverse neighbors
            for (auto nbr : l[node]) {
                int neigh = nbr.first;
                double weight = nbr.second;

                if (dist[node] + log(weight) > dist[neigh]) {
                    dist[neigh] = dist[node] + log(weight);
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        Graph g(n);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            double wt = succProb[i];
            g.addEdge(a, b, wt);
        }
        vector<double> temp = g.dijkstra(start_node);
        if (temp[end_node] == -1e18)
            return 0;

        return exp(temp[end_node]);
    }
};
