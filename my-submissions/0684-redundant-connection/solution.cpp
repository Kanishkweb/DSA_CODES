class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path Compression
    }

    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a; // Union by Size
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (dsu.find(a) == dsu.find(b)) {
                return {a, b};
            }
            dsu.unionSet(a, b);
        }
        return {};
    }
};
