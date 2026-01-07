class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // use set to remove the duplicate
        set<vector<int>> st(intervals.begin(), intervals.end());
        // Convert back to vector
        intervals.clear();
        vector<vector<int>> tempVec(st.begin(), st.end());
        intervals = tempVec;
        // edge case
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> result;
        vector<int> a = intervals[0];
        vector<int> b;
        int i = 1;
        int tempA = a[0]; // initialize by this
        int tempB = a[1];
        while (i <= intervals.size()) {
            if (i < intervals.size()) {
                b = intervals[i];
            }
            if (tempB >= b[0] && a != b) {
                // overlapping
                if (tempB <= b[1]) {
                    tempB = b[1];
                }
                a = b;
            } else {
                // non - overlapping
                if (a[1] >= tempB) {
                    result.push_back({tempA, a[1]});

                } else {
                    result.push_back({tempA, tempB});
                }

                a = b;
                tempA = a[0];
                tempB = a[1];
            }
            i++;
        }
        return result;
    }
};
