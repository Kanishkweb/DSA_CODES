class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            long long square = (long long)mid*mid;
            if(square <= x){
                start = mid+1;
                ans = mid;
            } else{
                end = mid-1;
            }
        }
        return ans;
    }
};
