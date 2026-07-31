class Solution {
public:
    int calcSum(int num){
        int total = 0;
        while(num > 0){
            total += num % 10;
            num = num / 10;
        }
        return total;
    }
    int largestInteger(int n, int s) {
        // case for impossible situation 
        int tut = 0;
        for(int i = 0;i<n;i++){
            tut += 9;
        }
        if(s > tut){
            return -1;
        } else if(s ==0){
            return 0;
        }
        int num = pow(10,n);
        cout << num << endl;
        for(int i = num-1;i>=0;i--){
            // digit seperation logic
            if(calcSum(i) == s) return i;
        }
        return -1;
    }
};
