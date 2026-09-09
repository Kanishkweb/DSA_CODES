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

        parent[b] = a;       // Union by Size
        size[a] += size[b];
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int N = connections.size();
        if(N < n-1) return -1;

        DSU dsu(n);

        for(auto & con : connections){
            int a = con[0];
            int b = con[1];
            dsu.unionSet(a,b);
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            if(dsu.find(i) == i){
                count++;
            }
        }

        return count-1;
    }
};
