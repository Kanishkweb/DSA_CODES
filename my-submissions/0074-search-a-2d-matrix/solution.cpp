class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n < 1)
            return false;
        int totalEle = m * n;
        int start = 0;
        int end = totalEle - 1;
        int row = 0;
        int col = 0;
        // in which row mid ele is findable
        while (start <= end) {
            int mid = start + (end - start) / 2;
            row = mid / n;
            col = mid % n;
            cout << matrix[row][col] << endl;
            if(target == matrix[row][col]){
                return true;
            } else if (target > matrix[row][col]) {
                start = mid+1;
            } else{
                end = mid - 1;
            }
        }
        return false;
    }
};
