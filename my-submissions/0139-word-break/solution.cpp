class Solution {
public:
    class TrieNode {
    public:
        bool isEnd = false;
        TrieNode* children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    bool solve(TrieNode* root, string& s, int idx, vector<int>& dp) {
        // basecase
        if (idx == s.length())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        TrieNode* curr = root;

        for (int i = idx; i < s.length(); i++) {
            int n = s[i] - 'a';
            if (!curr->children[n])
                break;
            curr = curr->children[n];
            if (curr->isEnd) {
                if (solve(root, s, i + 1, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        // if not exist in the TrieNode
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // time to fill the trie
        TrieNode* root = new TrieNode();
        for (int i = 0; i < wordDict.size(); i++) {
            TrieNode* curr = root;
            for (char ch : wordDict[i]) {
                int n = ch - 'a';
                if (!curr->children[n]) {
                    curr->children[n] = new TrieNode();
                }
                curr = curr->children[n];
            }
            curr->isEnd = true;
        }
        vector<int> dp(s.length(), -1);
        return solve(root, s, 0, dp);
    }
};
