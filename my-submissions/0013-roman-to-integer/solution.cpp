class Solution {
public:
    unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                   {'L', 50},  {'C', 100}, {'D', 500},
                                   {'M', 1000}};
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            bool op = 0;
            if (i < s.length() - 1) {
                if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    sum += mp[s[i + 1]] - mp[s[i]];
                    i++;
                } else if (s[i] == 'X' &&
                           (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    sum += mp[s[i + 1]] - mp[s[i]];
                    i++;
                } else if (s[i] == 'C' &&
                           (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    sum += mp[s[i + 1]] - mp[s[i]];
                    i++;
                } else {
                    op = 1;
                }
            } else{
                op = 1;
            }
            if (op) {
                sum += mp[s[i]];
            }
        }
        return sum;
    }
};
