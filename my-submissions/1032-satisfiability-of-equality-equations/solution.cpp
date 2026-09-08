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
        int N = 200;
        DSU dsu(N);

        for (auto& eq : equations) {
            int a = eq[0];
            int b = eq[3];
            string comp = eq.substr(1, 2);
            if (comp == "==") {
                dsu.unionSet(a, b);
            }
        }

        // now lets check all the != a and b
        for (auto& eq : equations) {
            int a = eq[0];
            int b = eq[3];
            string comp = eq.substr(1, 2);
            if (comp == "!=" && dsu.find(a) == dsu.find(b)) {
                return false;
            }
        }
        return true;
    }
};
