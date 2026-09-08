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
    int removeStones(vector<vector<int>>& stones) {
        int offSet = 100001;
        int N = 200002;

        DSU dsu(N);

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + offSet;

            dsu.unionSet(row, col);
        }

        unordered_set<int> components;
        for (auto& stone : stones) {
            // int col = stone[1] + offSet;
            int row = stone[0];

            components.insert(dsu.find(row));
        }

        return stones.size() - components.size();
    }
};
