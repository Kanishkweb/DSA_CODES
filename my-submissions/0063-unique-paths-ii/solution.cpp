class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>&dp) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (i == m - 1 && j == n - 1) {
            // robot reached at the star;
            return 1; // there is a path exist;
        }
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(obstacleGrid, i + 1, j,dp);
        int right = solve(obstacleGrid, i, j + 1,dp);
        dp[i][j] = down + right;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // edge cases
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1) return 0;
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return solve(obstacleGrid, 0, 0,dp);
    }
};
