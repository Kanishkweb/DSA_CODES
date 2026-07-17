class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>>adj(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (vals[b] > 0) {
                adj[a].push_back(b);
                degree[a]++;
            }
            if (vals[a] > 0) {
                adj[b].push_back(a);
                degree[b]++;
            }
        }

        int result = vals[0];
        for (int i = 0; i < n; i++) {
            int count = vals[i];
            sort(adj[i].begin(),adj[i].end(),[&](int a , int b){
                return vals[a] > vals[b];
            }); // desc
            for(int j = 0;j<min(k,(int)adj[i].size());j++){
                int val = adj[i][j];
                count += vals[val];
            }
            result = max(result,count);
        }
        return result;
    }
};
