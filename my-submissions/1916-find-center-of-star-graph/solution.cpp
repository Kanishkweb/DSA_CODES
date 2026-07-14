class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = m+1; // total no of nodes;
        vector<int>indegree(n+1,0);

        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            indegree[a]++;
            indegree[b]++;
        }
        int ansIdx = 0;
        int maxIn = INT_MIN;
        for(int i = 1;i<=n;i++){
            if(maxIn < indegree[i]){
                maxIn = indegree[i];
                ansIdx = i;
            }
        }
        return ansIdx;
    }
};
