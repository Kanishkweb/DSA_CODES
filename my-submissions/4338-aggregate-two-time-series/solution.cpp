class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        unordered_set<int> st;
        unordered_map<int, int> s1;
        unordered_map<int, int> s2;

        for (int i = 0; i < series1.size(); i++) {
            int a = series1[i][0];
            int b = series1[i][1];
            s1[a] = b;
            st.insert(a);
        }

        for (int i = 0; i < series2.size(); i++) {
            int a = series2[i][0];
            int b = series2[i][1];
            s2[a] = b;
            st.insert(a);
        }

        int n = st.size();

        vector<int> timeStamp;
        for (auto &x : st)
            timeStamp.push_back(x);

        sort(timeStamp.begin(), timeStamp.end());

        vector<int> se1(n, 0);
        vector<int> se2(n, 0);
        vector<int> summedValue(n, 0);

        // Base case (last timestamp)
        if (s1.find(timeStamp[n - 1]) != s1.end())
            se1[n - 1] = s1[timeStamp[n - 1]];

        if (s2.find(timeStamp[n - 1]) != s2.end())
            se2[n - 1] = s2[timeStamp[n - 1]];

        summedValue[n - 1] = se1[n - 1] + se2[n - 1];

        // Fill remaining timestamps
        for (int i = n - 2; i >= 0; i--) {

            if (s1.find(timeStamp[i]) != s1.end())
                se1[i] = s1[timeStamp[i]];
            else
                se1[i] = se1[i + 1];

            if (s2.find(timeStamp[i]) != s2.end())
                se2[i] = s2[timeStamp[i]];
            else
                se2[i] = se2[i + 1];

            summedValue[i] = se1[i] + se2[i];
        }

        vector<vector<int>> result(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            result[i][0] = timeStamp[i];
            result[i][1] = summedValue[i];
        }

        return result;
    }
};
