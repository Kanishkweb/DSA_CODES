class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n);
        // iterate the edges
        for(int i = 0;i<n;i++){
            int a = edges[i];
            adj[a].push_back(i);
        }
        long long edgeScore = -1;
        int nodeName = 0;
        for(int i = 0;i<adj.size();i++){
            long long count = 0;
            for(int j = 0;j<adj[i].size();j++){
                count += adj[i][j];
            }
            if(edgeScore < count){
                edgeScore = count;
                nodeName = i;
            }
        }
        return nodeName;
    }
};
