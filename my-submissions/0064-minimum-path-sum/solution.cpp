class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();         
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int top = INT_MAX;
                int left = INT_MAX;
                if(i>0){
                    top = grid[i-1][j];
                }
                if(j>0){
                    left = grid[i][j-1];
                }
                grid[i][j] += min(top,left);
            }
        }
        return grid[m-1][n-1];
    }
};
