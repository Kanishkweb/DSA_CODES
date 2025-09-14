class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = INT_MAX;
        for (int i = 0; i < tasks.size(); i++) {
            int firstVal = tasks[i][0];
            int secondVal = tasks[i][1];
            int total = firstVal + secondVal;
            minTime = min(total, minTime);
        }
        return minTime;
    }
};
