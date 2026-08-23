class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        DSU dsu(n);
        int component = n;
        for (auto& comp : connections) {
            if (dsu.find(comp[0]) != dsu.find(comp[1])) {
                component--;
                dsu.unionSet(comp[0], comp[1]);
            }
        }
        return component - 1;
    }
};
