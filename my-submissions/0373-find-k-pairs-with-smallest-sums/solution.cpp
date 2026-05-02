class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size(); 
        typedef pair<int,pair<int,int>> p;
        // init pq
        priority_queue<p,vector<p>,greater<p>>pq;
        set<pair<int,int>>visited;
        // push_first_pair_in_queue
        pq.push({nums1[0]+nums2[1],{0,0}}); // first element is always sorted
        visited.insert({0,0});
        vector<vector<int>>result;
        while(k > 0 && !pq.empty()){
            auto [i,j] = pq.top().second;
            result.push_back({nums1[i],nums2[j]});
            pq.pop();
            k--;
            // push two pair in pq also check the boundation
            if(i+1 < m && j < n && visited.find({i+1,j}) == visited.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if(i < m && j+1 < n && visited.find({i,j+1}) == visited.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};
