class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() < 1) return 0;
        stringstream ss(s);
        string word;
        string last;
        while(ss >> word){
            last = word;
        }
        return last.length();
    }
};
