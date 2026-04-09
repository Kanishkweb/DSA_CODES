class Solution {
public:
    class Graph {
        int V;
        list<pair<int, int>>* l;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<pair<int, int>>[V];
        }

        void addEdge(int a, int b, int wt) {
            l[a].push_back({b, wt});
            l[b].push_back({a, wt});
        }

        vector<int> dijkstra(int src) {
            // distance array
            vector<int> dist(V, INT_MAX);

            // min heap-> (node,distance);
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            // init
            dist[src] = 0;
            pq.push({src, 0});

            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();

                int node = top.first;
                int currDist = top.second;

                // skip outdated entries
                if (currDist > dist[node])
                    continue;

                // traverse neighbours
                for (auto nbr : l[node]) {
                    int neigh = nbr.first;
                    int weight = nbr.second;

                    if (dist[node] + weight < dist[neigh]) {
                        dist[neigh] = dist[node] + weight;
                        pq.push({neigh, dist[neigh]});
                    }
                }
            }
            return dist;
        }

        void dfs(vector<bool>& visited, int node, int& count, int dt) {
            visited[node] = true;

            for (auto& currNode : l[node]) {
                int a = currNode.first;
                int wt = currNode.second;

                if (dt - wt >= 0 && !visited[a]) {
                    count++;
                    dfs(visited, a, count, dt - wt);
                }
            }
            // backtrack
            visited[node] = false;
        }
    };
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // edge case
        if (n == 0)
            return 0;

        Graph g(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int wt = edges[i][2];
            g.addEdge(a, b, wt);
        }

        int minCity = INT_MAX;
        int minN = INT_MAX;
        // now run dijkstra's for every node
        for (int node = 0; node < n; node++) {
            vector<int> res = g.dijkstra(node);
            int count = 0;
            for (int i = 0; i < res.size(); i++) {
                if (res[i] <= distanceThreshold) {
                    count++;
                }
            }
            if (minN >= count) {
                minN = count;
                minCity = node;
            }
        }
        return minCity;
    }
};
