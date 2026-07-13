class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int result = INT_MIN;
        vector<int> indegree(n, 0);
        vector<vector<bool>> connect(n, vector<bool>(n, 0));

        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            connect[a][b] = 1;
            connect[b][a] = 1;
            indegree[a]++;
            indegree[b]++;
        }

        // try all the possible pairs;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int i_deg = indegree[i];
                int j_deg = indegree[j];
                int sum = i_deg + j_deg;
                if (connect[i][j]) {
                    sum--;
                }
                result = max(result, sum);
            }
        }
        return result;
    }
};
