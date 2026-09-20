class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // int a = intervals[i][0];
                int b = intervals[i][1];
                int x = intervals[j][0];
                // int y = intervals[j][1];
                if (b >= x) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
