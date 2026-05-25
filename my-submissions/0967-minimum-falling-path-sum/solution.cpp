class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = m-2;i>=0;i--){
            for(int j = 0;j<n;j++){
                int dl = INT_MAX;
                int b = INT_MAX;
                int dr = INT_MAX;
                if(j > 0){
                    dl = matrix[i+1][j-1];
                }
                b = matrix[i+1][j];
                if(j < n-1){
                    dr = matrix[i+1][j+1];
                }
                matrix[i][j] = matrix[i][j] + min(dl,min(b,dr));
            }
        }
        int result = INT_MAX;
        for(int j = 0;j<n;j++){
            result = min(result,matrix[0][j]);
        }
        return result;
    }
};
