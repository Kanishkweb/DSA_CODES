class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);

        for(int i = 0;i<edges.size();i++){
            int b = edges[i][1];
            indegree[b] = -1;
        }
        int count = 0;
        int result = -1;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                count++;
                result = i;
            }
        }
        if(count > 1) return -1;
        return result;
    }
};
