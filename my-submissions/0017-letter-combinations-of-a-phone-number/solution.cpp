class Solution {
public:
    vector<string> arr = {"aaa", "aaa", "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // for better indexing added "aaa";
    vector<string> result;
    void helper(string digits, string& str) {
        if (digits.length() == 0) {
            result.push_back(str);
            return;
        }

        string remaining = digits.substr(1);
        char ch = digits[0];
        int digit = ch - '0';
        for (int i = 0; i < arr[digit].length(); i++) {
            str += arr[digit][i];
            helper(remaining, str);
            str.pop_back(); // backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        string str = "";
        helper(digits, str);
        return result;
    }
};
