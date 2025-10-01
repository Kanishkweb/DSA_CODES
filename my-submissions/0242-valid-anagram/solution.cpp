class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return 0;
        unordered_map<char,int> mp;
        for(int i = 0;i<s.length();i++){
            if(!mp[s[i]]){
                mp[s[i]] = 1;
            } else {
                mp[s[i]]++;
            }
        }
        // for checking
        for(int i =0;i<t.length();i++){
            if(!mp[t[i]]){
                return 0;
            } else {
                mp[t[i]]--;
            }
        }
        return 1;
    }
};
