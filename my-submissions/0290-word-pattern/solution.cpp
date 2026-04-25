class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        unordered_map<char,string>mp;
        set<string>st;
        int i = 0;
        int len = 0;
        while(ss >> word){
            char ch = pattern[i];
            len++;
            if(mp.find(ch) == mp.end() && st.find(word) == st.end()){
                mp[ch] = word;
                st.insert(word);
            }
            i++;
        };
        if(len != pattern.size()) return false;
        stringstream rr(s);
        for(int j=0;j<pattern.size();j++){
            rr >> word;
            char ch = pattern[j];
            if(word != mp[ch]) return false;
            i++;
        }

        // after the last it is sure that it is true;
        return true;
    }
};
