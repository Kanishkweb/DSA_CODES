class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        // first find all the subarray
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = 0;
            int y = 0;
            for (int j = i; j < n; j++) {
                // nums[i];
                if (nums[j] % 2 == 0) {
                    x++;
                } else {
                    y++;
                }

                //  now check conditions for the valid subarray;
                if(y > 0 && (x*b) <= (a*y)){
                    ans++;
                }
            }
        }

        return ans;
    }
};
