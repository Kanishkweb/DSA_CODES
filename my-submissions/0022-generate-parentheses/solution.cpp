class Solution {
public:
    vector<string> result;
    void solve(int& n, int open, int close, string& temp) {
        // base case
        if (temp.length() == n * 2) {
            result.push_back(temp);
            return;
        }

        // main logic
        if (open < n) {
            temp.push_back('(');
            solve(n, open+1, close, temp);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            solve(n, open, close+1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        solve(n, 0, 0, temp);
        return result;
    }
};
