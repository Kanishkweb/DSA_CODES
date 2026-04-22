class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n>0){
            // make the right most set bit zero
            count++;
            n = n & (n-1);
        }
        return count;
    }
};
