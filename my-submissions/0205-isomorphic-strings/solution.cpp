class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mt;
        for (int i = 0; i < s.length(); i++) {
            // if (s[i] != t[i]) {
            // map and map reverse
            // before mapping the two edge case
            // case - 1 - do not store duplicate value
            // case - 2 - check if t[i] is present in mt map; if present
            // return false;
            if (!mp[s[i]]) {
                if (mt[t[i]]) {
                    return false;
                }
                mp[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            // }
        }
        // mapping done now lets compare our new string to the original one
        for(int i = 0;i<t.length();i++){
            if(mp[s[i]] != t[i]) return false;
        }
        return true;
    }
};
