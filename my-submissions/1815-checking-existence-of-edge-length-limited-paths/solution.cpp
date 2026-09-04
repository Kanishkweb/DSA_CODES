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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i = 0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        // sort both of the list
        sort(edgeList.begin(),edgeList.end(),[&](vector<int>&a,vector<int>&b){
            return a[2] < b[2];
        });

        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b){
            return a[2] < b[2];
        });

        int j = 0; // pointer for edgeList;
        vector<bool>ans(queries.size());
        //  traverse all the queries;
        for(int i = 0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int thres = queries[i][2];
            int idx = queries[i][3];

            while(j < edgeList.size() && edgeList[j][2] < thres){
                int x = edgeList[j][0];
                int y = edgeList[j][1];
                dsu.unionSet(x,y);
                j++;
            }

            if(dsu.find(a) == dsu.find(b)){
                ans[idx] = true;
            }
        }
        return ans;
    }
};
