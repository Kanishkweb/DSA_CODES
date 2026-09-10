class Solution {
public:

    bool DFS(vector<vector<int>>&graph,vector<int>&color,int node,int currColor){
        color[node] = currColor;

        for(auto & neigh : graph[node]){
            if(color[neigh] == currColor){
                return false;
            }
            if(color[neigh] == -1){
                int newColor = 1 - currColor;
                if(DFS(graph,color,neigh,newColor) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);

        for(auto & op : dislikes){
            int a = op[0];
            int b = op[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int>color(n+1,-1);
        for(int i = 1;i<=n;i++){
            if(color[i] == -1){
                if(DFS(graph,color,i,1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
