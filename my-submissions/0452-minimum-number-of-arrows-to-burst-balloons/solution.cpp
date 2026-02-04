class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // edge cases

        // sort
        sort(points.begin(),points.end());
        vector<vector<int>>result;
        result.push_back(points[0]);
        int count = 1;
        for(int i =1;i<points.size();i++){
            int n = result.size()-1;
            if(result[n][1] >= points[i][0]){
                // overlapping
                result[n][0] = max(result[n][0],points[i][0]);
                result[n][1] = min(result[n][1],points[i][1]);
                continue;
            } else {
                // non overlapping
                result.push_back(points[i]);
                count++;
            }
        }

        return count;
    }
};
