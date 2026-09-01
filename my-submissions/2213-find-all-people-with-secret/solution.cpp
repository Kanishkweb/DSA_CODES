class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        parent[y] = x;
    }

    void reset(int x) {
        parent[x] = x;
    }
};

class Solution {
public:
    vector<int> findAllPeople(
        int n,
        vector<vector<int>>& meetings,
        int firstPerson
    ) {
        DSU dsu(n);

        // Initially 0 and firstPerson know the secret
        dsu.unite(0, firstPerson);

        // Process meetings chronologically
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int m = meetings.size();

        int i = 0;

        while (i < m) {

            // Find all meetings having the same time
            int j = i;

            while (j < m &&
                   meetings[j][2] == meetings[i][2]) {
                j++;
            }

            // People involved at this timestamp
            vector<int> people;

            // Temporarily union all meetings
            for (int k = i; k < j; k++) {

                int x = meetings[k][0];
                int y = meetings[k][1];

                dsu.unite(x, y);

                people.push_back(x);
                people.push_back(y);
            }

            // Remove temporary connections
            // from components that don't know the secret
            for (int person : people) {

                if (dsu.find(person) != dsu.find(0)) {
                    dsu.reset(person);
                }
            }

            i = j;
        }

        // Everyone connected to 0 knows the secret
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
