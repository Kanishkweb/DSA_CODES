class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n+1, 0);
        vector<unordered_set<int>> arr(n + 1);
        // fill the indegree
        for (int i = 0; i < edges.size(); i++) {
            // both side indirected edges
            int a = edges[i][0];
            int b = edges[i][1];
            arr[a].insert(b);
            arr[b].insert(a);
            indegree[a]++;
            indegree[b]++;
        }

        int result = INT_MAX;
        // now check for all of the combinations
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    // now condition for the trio case
                    bool a = 0;
                    bool b = 0;
                    bool c = 0;
                    if (arr[i].find(j) != arr[i].end() &&
                        arr[i].find(k) != arr[i].end()) {
                        a = 1;
                    }
                    if (arr[j].find(i) != arr[j].end() &&
                        arr[j].find(k) != arr[j].end()) {
                            b = 1;
                    }
                    if (arr[k].find(i) != arr[k].end() &&
                        arr[k].find(j) != arr[k].end()) {
                            c = 1;
                    }
                    if(a && b && c){
                        int sum = indegree[i] + indegree[j] + indegree[k] - 6;
                        result = min(result,sum);
                    }
                }
            }
        }
        if(result == INT_MAX) return -1;
        return result;
    }
};
