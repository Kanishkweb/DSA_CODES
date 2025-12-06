class Solution {
public:
    vector<vector<int>> result;

    void helper(int n, int k, int index, vector<int>& temp) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        for (int i = index; i <= n;i++) {
            temp.push_back(i);
            helper(n, k, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        int index = 1;
        helper(n, k, index, temp);
        return result;
    }
};
