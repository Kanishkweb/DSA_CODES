class Solution {
public:
    int dp[366];
    int n;
    int binarySearch(vector<int>& days, int target) {
        int low = 0;
        int high = days.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (days[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    int solve(vector<int>& days, vector<int>& costs, int idx) {
        // base case
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        // main logic
        int oneday = INT_MIN;
        int sevenday = INT_MIN;
        int day30 = INT_MIN;
        oneday = costs[0] + solve(days, costs, idx + 1);
        sevenday =
            costs[1] + solve(days, costs, binarySearch(days, days[idx] + 6));
        day30 =
            costs[2] + solve(days, costs, binarySearch(days, days[idx] + 29));

        return dp[idx] = min(oneday, min(sevenday, day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, 0); // also currRange;
    }
};
