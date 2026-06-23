class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        unordered_set<string> mp;
        // build the map first
        for (int i = 1; i <= 26; i++) {
            string key = to_string(i);
            mp.insert(key);
        }

        // now tabulation approach
        int idxPlusOne = 1;
        int idxPlusTwo = 0;
        int currIdx = 0;
        for (int idx = n - 1; idx >= 0; idx--) {
            // main logic
            int breakOne = 0;
            if (mp.find(s.substr(idx, 1)) != mp.end()) {
                breakOne += idxPlusOne;
            }
            int breakTwo = 0;
            if (idx + 2 <= n && mp.find(s.substr(idx, 2)) != mp.end()) {
                breakTwo += idxPlusTwo;
            }
            currIdx = breakOne + breakTwo;
            idxPlusTwo = idxPlusOne;
            idxPlusOne = currIdx;
        }
        return currIdx;
    }
};
