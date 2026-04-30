class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // transpose
        for(int i = 0;i<m;i++){
            for(int j = i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse
        for(int row = 0;row<m;row++){
            reverse(matrix[row].begin(),matrix[row].end());
        }
    }
};
