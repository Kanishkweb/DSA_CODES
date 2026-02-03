class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        typedef pair<int, pair<int, int>> p;
        set<pair<int, int>> visited;
        priority_queue<p, vector<p>, greater<p>> pq;

        int m = nums1.size();
        int n = nums2.size();

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0}); // mark as visited at this index;
        vector<vector<int>> result;

        while (k-- && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                int sum = nums1[i] + nums2[j + 1];
                pq.push({sum, {i, j + 1}});
                visited.insert({i, j + 1});
            }
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                int sum = nums1[i + 1] + nums2[j];
                pq.push({sum, {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }
        return result;
    }
};
