class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long result = 0;
        for(auto & interval : intervals){
            int a = interval[0];
            int b = interval[1];

            while(!pq.empty() && pq.top() < a){
                pq.pop();
            }
            result = result + pq.size();
            pq.push(b);
        }
        return result;
    }
};
