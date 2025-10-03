class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        if (n == 1)
            return true;
        while (seen.find(n) == seen.end()) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            n = sum;
            // also store the value in set
        }
        return n == 1;
    }
};
