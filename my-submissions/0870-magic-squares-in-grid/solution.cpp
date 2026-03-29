class Solution {
public:
    bool solve(int row, int col, vector<vector<int>>& grid) {
        vector<int> freq(10, 0);

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || freq[val]++) {
                    return false;
                }
            }
        }
        // for checking all the rows
        for (int i = row; i < row + 3; i++) {
            int rowSum = 0;
            for (int j = col; j < col + 3; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != 15)
                return false;
        }
        // for checking all the columns
        for (int j = col; j < col + 3; j++) {
            int colSum = 0;
            for (int i = row; i < row + 3; i++) {
                colSum += grid[i][j];
            }
            if (colSum != 15)
                return false;
        }
        // check the two diagonal
        int diaSumL = 0;
        for (int i = row, j = col; i < row + 3 && j < col + 3; i++, j++) {
            diaSumL += grid[i][j];
        }
        if (diaSumL != 15)
            return false;
        int diaSumR = 0;
        for (int i = row, j = col + 2; i < row + 3 && j >= col; i++, j--) {
            diaSumR += grid[i][j];
        }
        if (diaSumR != 15)
            return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // edge case
        if (m < 3 || n < 3)
            return 0; // no 3 x 3 magic square exist

        // vut the 3x3 magic square matrix
        int ans = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (solve(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
