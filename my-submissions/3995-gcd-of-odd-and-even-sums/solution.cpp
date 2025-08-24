class Solution {
public:
int gcdcalc(int a,int b){
    if(b == 0){
        return a;
    } else {
        return gcdcalc(b,a%b);
    }
}
    int gcdOfOddEvenSums(int n) {
        // euclidean algorithm;
        long long int sumOdd = n*n;
        long long int sumEven = n*(n+1);
        return gcdcalc(sumOdd,sumEven);
    }
};
