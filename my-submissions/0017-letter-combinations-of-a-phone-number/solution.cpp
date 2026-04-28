class Solution {
public:
    vector<string> result;
    void solve(string digits, unordered_map<char, string>& mp, string& temp,
               int idx) {
        if (temp.length() == digits.length()) {
            result.push_back(temp);
            return;
        }

        string op = mp[digits[idx]];
        for (int i = 0; i < op.length(); i++) {
            // do
            temp.push_back(op[i]);
            // explore
            solve(digits, mp, temp, idx + 1);
            // undo
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        string temp;
        int idx = 0;
        solve(digits, mp, temp, idx);
        return result;
    }
};
