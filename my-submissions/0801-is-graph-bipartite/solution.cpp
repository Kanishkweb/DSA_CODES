class Solution {
public:
    bool DFS(vector<vector<int>>& graph,int curr, vector<int>&color, int currColor){
        color[curr] = currColor;

        for(auto & neigh : graph[curr]){
            if(color[neigh] == color[curr]){
                return false;
            }

            if(color[neigh] == -1){ // never visited
                int newColor = 1 - currColor;
                if(DFS(graph,neigh,color,newColor)== false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // no of nodes;
        vector<int>color(n,-1); // no node colored in the start

        // red = 1
        // green = 0
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(DFS(graph,i,color,1) == false){
                    return false;
                }
            }
        }

        return true;
    }
};
