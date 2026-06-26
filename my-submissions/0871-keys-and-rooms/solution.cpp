class Solution {
public:
    void dfs(vector<vector<int>>&rooms,vector<int>&visited,int node){
        visited[node] = 1; // mark as true

        for(auto& currNode : rooms[node]){
            if(!visited[currNode]){
                dfs(rooms,visited,currNode);
            }
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n);
        dfs(rooms,visited,0);
        // check if all the ele is visited
        for(auto& ele : visited){
            if(ele == false) return false;
        }
        return true;
    }
};
