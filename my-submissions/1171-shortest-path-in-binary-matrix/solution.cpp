class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<int> row = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> col = {-1, 0, 1, 1, 1, 0, -1, -1};

        queue<pair<int, int>> q;
        q.push({0, 0}); // start from source 0,0 --> desitination (n-1,n-1);
        grid[0][0] = 1;
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();
                int a = p.first;
                int b = p.second;
                if (a == n - 1 && b == n - 1) {
                    return level;
                }
                for (int i = 0; i < 8; i++) {
                    int trow = row[i] + a;
                    int tcol = col[i] + b;
                    if (trow < 0 || tcol < 0 || trow >= n || tcol >= n ||
                        grid[trow][tcol] == 1) {
                        continue;
                    }
                    grid[trow][tcol] = 1; // marked as visited
                    q.push({trow, tcol});
                }
            }
            level++;
        }
        return -1;
    }
};
