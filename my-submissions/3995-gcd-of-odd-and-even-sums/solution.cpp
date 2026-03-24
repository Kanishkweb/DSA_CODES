class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // calc the number of the two integer
        if (n == 0)
            return 0;
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        
        int result = min(sumOdd,sumEven);
        while(result > 0){
            if(sumEven % result == 0 && sumOdd % result == 0){
                break;
            }
            result--;
        }
        return result;
    }
};
