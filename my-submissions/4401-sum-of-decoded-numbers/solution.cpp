class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long powerMod(long long x , long long y){
        long long result = 1;
        if(y == 0) return 1;
        if(y % 2 == 0){
            long long a = powerMod(x,y/2);
            return (a * a) % MOD;
        } else {
            // odd 
            long long a = powerMod(x,y/2);
            return (a * a  % MOD * x) % MOD;
        }
    }
    int sumDecoded(vector<long long>& nums) {
        long long n = nums.size();

        long long result = 0;
        // traverse all the num
        for (long long i = 0; i < n; i++) {
            long long num = nums[i];
            long long width = nums[i] % 10;
            long long d = floor(nums[i] / 10);
            // you have to take the integer according to the width
            long long totalDigits = log10(abs(d)) + 1;
            long long m = totalDigits - width;
            long long power = pow(10, m);
            long long x = d / power;
            long long y = d % power;
            result += powerMod(x, y);
        }
        return result % MOD;
    }
};
