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
    bool equationsPossible(vector<string>& equations) {

        DSU dsu(26);

        // Step 1: Process all "==" equations
        for (auto &eq : equations) {

            int a = eq[0] - 'a';
            int b = eq[3] - 'a';

            if (eq[1] == '=') {
                dsu.unionSet(a, b);
            }
        }

        // Step 2: Check all "!=" equations
        for (auto &eq : equations) {

            int a = eq[0] - 'a';
            int b = eq[3] - 'a';

            if (eq[1] == '!') {

                // If they belong to same component,
                // they cannot be different.
                if (dsu.find(a) == dsu.find(b)) {
                    return false;
                }
            }
        }

        return true;
    }
};
