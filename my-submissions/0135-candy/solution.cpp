class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> idx(ratings.size());

        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&ratings](int i, int j) { return ratings[i] < ratings[j]; });
        vector<int> candy(n, 0);
        for (int i = 0; i < idx.size(); i++) {
            int rIdx = idx[i];
            cout << ratings[rIdx] << endl;
            int neighbour = 0;
            int cn = 0; // candy neighbour;
            // check left neighbour
            if (rIdx > 0 && ratings[rIdx] > ratings[rIdx - 1]) {
                cn = max(cn, candy[rIdx - 1]);
            }
            // check right neighbour
            if (rIdx < n - 1 && ratings[rIdx] > ratings[rIdx + 1]) {
                cn = max(cn, candy[rIdx + 1]);
            }
            candy[rIdx] = cn + 1;
        }
        int totalCandy = 0;
        for (int i = 0; i < candy.size(); i++) {
            totalCandy += candy[i];
        }
        return totalCandy;
    }
};
