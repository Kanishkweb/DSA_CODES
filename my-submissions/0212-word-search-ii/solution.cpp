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
    bool isEmpty(TrieNode* node) {
    for (int i = 0; i < 26; i++)
        if (node->children[i])
            return false;
    return true;
}

void solve(TrieNode* root, int i, int j, vector<vector<char>>& board,
           vector<vector<int>>& visited, string &res, vector<string>& result) {

    if (root->isEnd) {
        result.push_back(res);
        root->isEnd = false;
    }

    int m = board.size();
    int n = board[0].size();

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    for(int l=0;l<4;l++){
        int row=i+dy[l];
        int col=j+dx[l];

        if(row<0||row>=m||col<0||col>=n||visited[row][col]) continue;

        int place = board[row][col]-'a';
        TrieNode* child = root->children[place];

        if(child==NULL) continue;

        visited[row][col]=1;
        res.push_back(board[row][col]);

        solve(child,row,col,board,visited,res,result);

        // BACKTRACK
        res.pop_back();
        visited[row][col]=0;

        // ⭐ TRIE PRUNING (KEY FIX)
        if(isEmpty(child) && child->isEnd==false){
            delete child;
            root->children[place]=NULL;
        }
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
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string res = "";
                // visited.assign(m, vector<int>(n, 0));
                
                int place = board[i][j] - 'a';
                
                if (root->children[place] != NULL) {
                    visited[i][j] = 1;
                    res.push_back(board[i][j]);
                    
                    solve(root->children[place], i, j, board, visited, res, result);
                     visited[i][j] = 0;
                }
            }
        }
        return result;
    }
};
