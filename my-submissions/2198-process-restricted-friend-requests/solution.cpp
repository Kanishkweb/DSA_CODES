class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); // path compression
    }
    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            size[a]++;
            return;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        DSU dsu(n);

        vector<bool> ans(requests.size()); // auto - 0;
        // traverse
        for (int i = 0; i < requests.size(); i++) {
            vector<int> tempParent;
            vector<int> tempSize;
            int a = requests[i][0];
            int b = requests[i][1];
            tempParent = dsu.parent;
            tempSize = dsu.size;
            // perform the union operation
            dsu.unionSet(a, b);
            // now check all the restrictions
            bool safe = true;
            for (auto& res : restrictions) {
                int x = dsu.find(res[0]);
                int y = dsu.find(res[1]);
                if (x == y) {
                    dsu.parent = tempParent;
                    dsu.size = tempSize;
                    safe = false;
                    break;
                }
            }
            if (safe) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
