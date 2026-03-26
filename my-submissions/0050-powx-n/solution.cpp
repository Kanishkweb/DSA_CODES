class Solution {
public:
    double solve(double x , int n){
        if(n == 0) {
            return 1;
        }
        if(n%2 == 0){
            // means even
            double half = solve(x,n/2);
            return half * half;
        } else{
            // if odd
            double half = solve(x,n/2);
            return x * half * half;
        }
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / solve(x, n);
        }
        return solve(x,n);

    }
};
