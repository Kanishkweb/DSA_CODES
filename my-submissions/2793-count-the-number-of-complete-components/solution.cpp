class DSU {
    public:
        vector<int> parent,size,edge;

        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            edge.resize(n);

            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }

            return parent[x] = find(parent[x]); // Path Compression
        }

        void unionSet(int a , int b){
            a = find(a);
            b = find(b);

            if(a == b){
                edge[a]++;
                return;
            }

            if(size[a] < size[b]){
                swap(a,b);
            }

            parent[b] = a; // Union by size;
            edge[a]++;
            size[a] += size[b];

        }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        // traverse edges
        for(auto & edge : edges){
            int a = edge[0];
            int b = edge[1];

            dsu.unionSet(a,b);
        }

        // now the main logic
        int result = 0;
        for(int i = 0;i<n;i++){

            // only process root of each component
            if(dsu.find(i) != i) continue;

            
            int s = dsu.size[i];
            int e = dsu.edge[i];

            if(s*(s-1) == e*2){
                result++;
            }
        }
        return result;
    }
};
