class Solution {
public:
    vector<int> result;
    void solve(vector<vector<int>>& matrix, int a, int d, int m, int n) {
        int dir = 0;
        while (a <= m && d <= n) {
            if (dir == 0) {
                for (int i = d; i <= n; i++) {
                    result.push_back(matrix[a][i]);
                }
                a++;
            }
            if (dir == 1) {

                for (int i = a; i <= m; i++) {
                    result.push_back(matrix[i][n]);
                }
                n--;
            }
            if (dir == 2) {

                for (int i = n; i >= d; i--) {
                    result.push_back(matrix[m][i]);
                }
                m--;
            }
            if (dir == 3) {

                for (int i = m; i >= a; i--) {
                    result.push_back(matrix[i][d]);
                }
                d++;
            }
            (dir == 4 ? dir = 0 : dir++);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int a = 0; // row
        int d = 0; // col
        m = m - 1;
        n = n - 1;
        solve(matrix, a, d, m, n);
        return result;
    }
};
