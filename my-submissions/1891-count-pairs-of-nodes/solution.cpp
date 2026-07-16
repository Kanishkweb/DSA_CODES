class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges,
                           vector<int>& queries) {

        vector<int> degree(n + 1, 0);

        // count parallel edges between (u,v)
        unordered_map<long long, int> cnt;

        for (auto &e : edges) {
            int u = e[0], v = e[1];

            degree[u]++;
            degree[v]++;

            if (u > v) swap(u, v);

            long long key = 1LL * u * (n + 1) + v;
            cnt[key]++;
        }

        vector<int> sortedDeg(degree.begin() + 1, degree.end());
        sort(sortedDeg.begin(), sortedDeg.end());

        vector<int> ans;

        for (int q : queries) {

            // Count pairs with degree sum > q
            long long total = 0;

            int l = 0, r = n - 1;

            while (l < r) {
                if (sortedDeg[l] + sortedDeg[r] > q) {
                    total += (r - l);
                    r--;
                } else {
                    l++;
                }
            }

            // Remove over-counted connected pairs
            for (auto &p : cnt) {

                long long key = p.first;
                int common = p.second;

                int u = key / (n + 1);
                int v = key % (n + 1);

                int sum = degree[u] + degree[v];

                if (sum > q && sum - common <= q) {
                    total--;
                }
            }

            ans.push_back((int)total);
        }

        return ans;
    }
};
