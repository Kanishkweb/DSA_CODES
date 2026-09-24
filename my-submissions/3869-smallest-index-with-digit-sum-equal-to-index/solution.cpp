class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            int num = nums[i];
            while(num > 0){
                int temp = num%10;
                num /= 10;
                sum += temp;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};
