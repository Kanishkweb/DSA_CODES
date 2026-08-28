class DSU {
    public:
        vector<int>parent;
        vector<int>size;
        vector<int>path;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            path.resize(n,INT_MAX);
            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            // we have to return the parent of x
            if(parent[x] == x){
                return x;
            }

            return parent[x] = find(parent[x]); // path compression
        }

        void unionSet(int a , int b,int c){
            a = find(a);
            b = find(b);

            if(a == b) {
                path[a] = min(path[a], c);
                return;
            }

            // now check the rank
            if(size[a] < size[b]){
                // swap the values 
                swap(a,b); //  so that a will become parent;
            }

            parent[b] = a;
            size[a] += size[b];
            path[a] = min({path[a], path[b], c});
        }
};


class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);

        // lets traverse the roads and union it;
        for(auto & road : roads){
            int a = road[0];
            int b = road[1];
            int c = road[2];
            dsu.unionSet(a,b,c);
        }
        int small = INT_MAX;
        return dsu.path[dsu.find(1)];
    }
};
