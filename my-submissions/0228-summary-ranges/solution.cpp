class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<string> arr;
        int a = nums[0];
        int b = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (b + 1 != nums[i]) {
                if (a == b) {
                    arr.push_back(to_string(a));
                } else {
                    string str = to_string(a) + "->" + to_string(b);
                    arr.push_back(str);
                }
                a = nums[i];
                b = nums[i];
            } else if (b + 1 == nums[i]) {
                b = nums[i];
            }
        }
        if (a == b) {
            arr.push_back(to_string(a));
        } else {
            string str = to_string(a) + "->" + to_string(b);
            arr.push_back(str);
        }
        return arr;
    }
};
