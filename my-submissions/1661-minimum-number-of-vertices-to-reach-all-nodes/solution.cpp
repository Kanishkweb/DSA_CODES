class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>result;
        vector<int>indegree(n,0);
        for(int i = 0;i<edges.size();i++){
            int dir = edges[i][1];
            indegree[dir]++;
        }
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] == 0){
                result.push_back(i);
            }
        }
        return result;
    }
};
