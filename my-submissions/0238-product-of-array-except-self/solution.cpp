class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        // storing prefix product values;
        int pr = 1;
        for(int i = 0;i<nums.size();i++){
            if(i == 0){
                prefix[i] = 1;
            } else {
                pr *= nums[i-1];
                prefix[i] = pr;
            }
        }
        pr = 1;
        // storing suffix product value;
        for(int i = n-1;i>=0;i--){
            if(i == n-1){
                prefix[i] *= 1;
            } else {
                pr *= nums[i+1];
                prefix[i] *= pr;
            }
        }

        return prefix;
    }
};
