class Solution {
public:
    bool checkRowCol(vector<vector<char>>& board, int m, int n) {
        set<char> st;
        for (int i = m; i < 3 + m; i++) {
            for (int j = n; j < 3 + n; j++) {
                if (st.find(board[i][j]) == st.end()) {
                    if (board[i][j] != '.') {
                        st.insert(board[i][j]);
                    }
                } else {
                    cout << "RowCOl" << endl;
                    return 0; // false
                }
            }
        }
        return 1;
    }
    bool checkCol(vector<vector<char>>& board) {
        int m = 9;
        int n = 9;
        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = 0; j < m; j++) {
                if (st.find(board[j][i]) == st.end()) {
                    if (board[j][i] != '.') {
                        st.insert(board[j][i]);
                    }
                } else {
                    cout << "col" << endl;
                    return 0; // false
                }
            }
        }
        return 1;
    }
    bool checkRow(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            set<int> st;
            for (int j = 0; j < n; j++) {
                if (st.find(board[i][j]) == st.end()) {
                    if (board[i][j] != '.') {
                        st.insert(board[i][j]);
                    }
                } else {
                    cout << "row" << endl;
                    return 0; // false;
                }
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int i = 0;
        int j = 0;
        while (i < 9) {
            while (j < 9) {
                if (checkRowCol(board, i, j) == 0) {
                    return 0;
                }
                j += 3;
            }
            j = 0;
            i += 3;
        }
        return checkRow(board) && checkCol(board);
    }
};
