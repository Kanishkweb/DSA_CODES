class Solution {
public:
    int minimumDeletions(string s) {
        int totalA = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a')
                totalA++;
        }
        int aAfter = totalA;
        int bBefore = 0;
        int result = aAfter + bBefore;
        for (int i = 0; i < s.length(); i++) {
            result = min(result, aAfter + bBefore);
            if (s[i] == 'a') {
                aAfter--;
            } else {
                bBefore++;
            }
        }
        result = min(result, aAfter + bBefore);
        return result;
    }
};
