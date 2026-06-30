class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id, int level) {

        int n = friends.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(id);
        visited[id] = true;

        int currLevel = 0;

        // BFS until desired level
        while (!q.empty() && currLevel < level) {
            int sz = q.size();

            while (sz--) {
                int person = q.front();
                q.pop();

                for (int fr : friends[person]) {
                    if (!visited[fr]) {
                        visited[fr] = true;
                        q.push(fr);
                    }
                }
            }

            currLevel++;
        }

        // Count video frequencies
        unordered_map<string, int> freq;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (string &video : watchedVideos[person]) {
                freq[video]++;
            }
        }

        // Store in vector for sorting
        vector<pair<string, int>> videos;

        for (auto &it : freq) {
            videos.push_back({it.first, it.second});
        }

        // Sort by frequency, then lexicographically
        sort(videos.begin(), videos.end(),
             [](pair<string, int> &a, pair<string, int> &b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        vector<string> ans;

        for (auto &it : videos)
            ans.push_back(it.first);

        return ans;
    }
};
