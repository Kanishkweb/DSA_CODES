class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int a = 0;
        int b = 0;
        int len = 0;
        while (b < s.length()) {
            if (!mp[s[b]]) {
                mp[s[b]] = 1;
            } else if (mp[s[b]]) {
                mp[s[b]]++;
            }

            while (mp[s[b]] > 1) {
                mp[s[a]]--;
                a++;
            }
            len = max(len, b - a + 1);
            b++;
        }
        return len;
    }
};
