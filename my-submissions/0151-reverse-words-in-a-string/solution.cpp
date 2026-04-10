class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word;
        stringstream ss(s);

        while(ss >> word){
            ans = word + (ans.empty() ? "" : " ") + ans;
        }
        return ans;
    }
};
