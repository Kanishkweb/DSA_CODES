class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int i = n;
        int carry = 0;
        while (i >= 0 && digits[i] == 9) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = 1;
            }
            i--;
        }
        if (i >= 0) {
            digits[i] = digits[i] + 1;
            carry = 0;
            i--;
        }
        if (carry > 0) {
            // add one in the starting
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
