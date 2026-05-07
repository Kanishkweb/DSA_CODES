class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd = false;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };
    vector<int> dy = {-1, 0, 1, 0}; // row
    vector<int> dx = {0, 1, 0, -1}; // col
    void solve(TrieNode* root, int i, int j, vector<vector<char>>& board,
               string& res, vector<string>& result) {
        int m = board.size();
        int n = board[0].size();

        if (root->isEnd) {
            result.push_back(res);
            root->isEnd = false;
        }

        for (int l = 0; l < 4; l++) {
            int row = i + dy[l];
            int col = j + dx[l];

            if (row < 0 || row >= m || col < 0 || col >= n) {
                continue;
            }

            if (board[row][col] == '$') {
                continue;
            }

            int place = board[row][col] - 'a';
            if (root->children[place] == NULL) {
                continue;
            }

            char oldChar = board[row][col];
            res.push_back(board[row][col]);
            board[row][col] = '$';

            solve(root->children[place], row, col, board, res, result);

            // Backtrack
            res.pop_back();
            board[row][col] = oldChar;
        }
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        // fill all the words in trie;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* curr = root;
            for (auto& op : words[i]) {
                int place = op - 'a';
                if (curr->children[place] == NULL) {
                    curr->children[place] = new TrieNode();
                }
                curr = curr->children[place];
            }
            curr->isEnd = true;
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string res = "";

                int place = board[i][j] - 'a';
                if (root->children[place] != NULL) {
                    char oldChar = board[i][j];
                    res.push_back(board[i][j]);
                    board[i][j] = '$';

                    solve(root->children[place], i, j, board, res, result);
                    board[i][j] = oldChar;
                }
            }
        }
        return result;
    }
};
