class Solution {
public:
    vector<string> result;
    bool checkValid(string str) {
        int count = 0;
        for (char c : str) {
            if (c == '(')
                count++;
            else
                count--;

            if (count < 0)
                return false; 
        }
        return count == 0;
    }

    void solve(int n, string str) {
        if (2 * n == str.length()) {
            if (checkValid(str)) {
                result.push_back(str);
            }
            return;
        }
        string tstr = str + "(";
        solve(n, tstr);
        tstr.pop_back();
        tstr = str + ")";
        solve(n, tstr);
    }
    vector<string> generateParenthesis(int n) {
        string str;
        solve(n, str);
        return result;
    }
};
