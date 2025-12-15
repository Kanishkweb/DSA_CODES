class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (mp.find(str) == mp.end()) {
                vector<string> temp;
                temp.push_back(strs[i]);
                mp[str] = temp;
            } else if (mp.find(str) != mp.end()) {
                vector<string> tp = mp[str];
                tp.push_back(strs[i]);
                mp[str] = tp;
            }
        }
        vector<vector<string>> result;
        for (auto& [key, vec] : mp) {
            result.push_back(vec);
        }

        return result;
    }
};
