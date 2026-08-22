class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<tuple<int,int,int>> cells;

        // Store: value, row, column
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                cells.push_back({matrix[r][c], r, c});
            }
        }

        // Sort by value
        sort(cells.begin(), cells.end());

        vector<int> rowRank(m, 0);
        vector<int> colRank(n, 0);

        vector<vector<int>> ans(m, vector<int>(n));

        int total = m * n;

        for (int start = 0; start < total; ) {

            int end = start;

            int value = get<0>(cells[start]);

            // Find all cells having same value
            while (end < total &&
                   get<0>(cells[end]) == value) {
                end++;
            }

            // DSU for this value group
            DSU dsu(end - start);

            vector<int> rowOwner(m, -1);
            vector<int> colOwner(n, -1);

            // Connect equal-valued cells
            // sharing the same row/column
            for (int i = start; i < end; i++) {

                int r = get<1>(cells[i]);
                int c = get<2>(cells[i]);

                int id = i - start;

                if (rowOwner[r] != -1)
                    dsu.unite(id, rowOwner[r]);

                rowOwner[r] = id;

                if (colOwner[c] != -1)
                    dsu.unite(id, colOwner[c]);

                colOwner[c] = id;
            }

            // Calculate rank needed for every component
            unordered_map<int, int> componentRank;

            for (int i = start; i < end; i++) {

                int r = get<1>(cells[i]);
                int c = get<2>(cells[i]);

                int id = i - start;
                int root = dsu.find(id);

                int rank = max(rowRank[r], colRank[c]) + 1;

                componentRank[root] =
                    max(componentRank[root], rank);
            }

            // Assign ranks
            for (int i = start; i < end; i++) {

                int r = get<1>(cells[i]);
                int c = get<2>(cells[i]);

                int id = i - start;
                int root = dsu.find(id);

                int rank = componentRank[root];

                ans[r][c] = rank;
            }

            // Update row/column ranks AFTER
            // processing the entire value group
            for (int i = start; i < end; i++) {

                int r = get<1>(cells[i]);
                int c = get<2>(cells[i]);

                rowRank[r] = max(rowRank[r], ans[r][c]);
                colRank[c] = max(colRank[c], ans[r][c]);
            }

            start = end;
        }

        return ans;
    }
};
