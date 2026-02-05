class Solution {
public:
    set<string> wordDic;

    bool solve(int idx, string &s, vector<int> &memo) {
        // base case -> reached end
        if (idx == s.size())
            return true;

        // already computed
        if (memo[idx] != -1)
            return memo[idx];

        string temp = "";

        for (int i = idx; i < s.size(); i++) {
            temp += s[i];

            // if word found in dictionary
            if (wordDic.find(temp) != wordDic.end()) {

                // try breaking remaining string
                if (solve(i + 1, s, memo))
                    return memo[idx] = true;
            }
        }

        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (string &w : wordDict)
            wordDic.insert(w);

        vector<int> memo(s.size(), -1);

        return solve(0, s, memo);
    }
};

