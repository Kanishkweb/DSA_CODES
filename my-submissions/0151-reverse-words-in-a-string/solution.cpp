class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string ullu;
        stringstream ss(s);

        while(ss >> ullu){
            ans = ullu + (ans.empty() ? "" : " ") + ans;
        }
        return ans;
    }
};
