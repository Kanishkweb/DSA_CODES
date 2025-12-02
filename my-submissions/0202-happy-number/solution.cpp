class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
        unordered_map<int, bool> mp;
        while (n != 1) {
            if (mp[n])
                return false;
            mp[n] = true;
            temp = n;
            int sum = 0;
            while (temp != 0) {
                int op = temp % 10;
                sum += op*op;
                temp = temp / 10;
            }
            n = sum; // saves the total 
        }
        return true;
    }
};
