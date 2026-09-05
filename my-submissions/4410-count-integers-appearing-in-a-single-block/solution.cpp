class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        unordered_set<int>invalid;
        int count = 0;
        int prev = nums[0];
        for(int i = 0;i<n;i++){
            int curr = nums[i];
            if(st.find(curr) == st.end()){
                count++;
                st.insert(curr);
                prev = curr;
            } else {
                if(prev == curr) continue;
                // already present in the st then
                if(invalid.find(curr) == invalid.end()){
                    count--;
                    invalid.insert(curr);
                }
                prev = curr;
            }
        }

        return count;
    }
};
