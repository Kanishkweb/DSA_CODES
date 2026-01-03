class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= 1) return s;
        int row = numRows;
        int col = s.length();
        vector<vector<char>> matrix(row, vector<char>(col, '9'));
        int j = 0;
        int m = 0; // row
        int n = 0; // col
        while (j < s.length()) {
            // up to down;
            for (int i = 0; i < numRows; i++) {
                if (j >= s.length())
                    break;
                matrix[i][n] = s[j++];
            }
            n++; // col change;
            // zig zag pattern;
            if (numRows > 2) {
                int start = numRows - 2; // -2 due to index
                int end = 0;
                for (int i = start; i > end; i--) {
                    if (j >= s.length())
                        break;
                    cout << i << endl;
                    matrix[i][n] = s[j++];
                    n++;
                }
            }
        }
        // read the string
        string result = "";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] != '9') {
                    result += matrix[i][j];
                }
            }
        }
        return result;
    }
};
