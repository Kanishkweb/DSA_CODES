class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& temp) {
        if (idx >= candidates.size() || target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(temp);
            return;
        }
        temp.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx, temp);
        temp.pop_back();
        solve(candidates, target, idx + 1, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx = 0;
        vector<int> temp;
        solve(candidates, target, idx, temp);
        return result;
    }
};
