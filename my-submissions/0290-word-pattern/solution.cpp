class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mt;
        string word;
        vector<string> arr;
        stringstream ss(s);

        while (ss >> word) {
            arr.push_back(word);
        }

        if (pattern.length() != arr.size())
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (mt.find(arr[i]) != mt.end()) {
                    return false;
                }
                mp[pattern[i]] = arr[i];
                mt[arr[i]] = pattern[i];
            }
        }
        // now check for the each word pattern;
        for (int i = 0; i < pattern.length(); i++) {
            if (mp[pattern[i]] != arr[i])
                return false;
        }
        return true;
    }
};
