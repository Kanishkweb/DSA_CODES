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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        // traverse the edges
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            dsu.unionSet(a, b);
        }

        long long ans = 0;
        long long previous = 0;
        for (long long i = 0; i < n; i++) {
            // i is a root
            if (dsu.find(i) == i) {

                long long curr = dsu.size[i];

                ans += curr * previous;

                previous += curr;
            }
        }

        return ans;
    }
};
