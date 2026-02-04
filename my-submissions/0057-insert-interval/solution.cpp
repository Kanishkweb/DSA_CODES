class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // edge cases
        if(intervals.size() == 0) return {newInterval};
        intervals.push_back(newInterval);
        // sort the interval array comparing the first element
        sort(intervals.begin(),intervals.end());
        // now the main logic
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            int n = result.size()-1;
            if(result[n][1] >= intervals[i][0]){
                // means overlapping
                result[n][0] = min(result[n][0],intervals[i][0]);
                result[n][1] = max(result[n][1],intervals[i][1]);
            } else{
                // means non-overlapping
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
