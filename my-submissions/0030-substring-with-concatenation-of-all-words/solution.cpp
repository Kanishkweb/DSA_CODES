class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int m = s.length();
        int n = words[0].length();

        unordered_map<string,int> mp;
        for(auto &w: words) mp[w]++;

        int wordCount = words.size();

        vector<int> result;

        for(int i = 0; i < n; i++) {

            int startIdx = i;
            int currWordCount = 0;

            unordered_map<string,int> currMap;

            for(int j = i; j + n <= m; j += n) {

                string str = s.substr(j,n);

                if(mp.find(str) != mp.end()) {

                    currMap[str]++;
                    currWordCount++;

                    while(currMap[str] > mp[str]) {

                        string leftWord = s.substr(startIdx,n);
                        currMap[leftWord]--;
                        currWordCount--;
                        startIdx += n;
                    }

                    if(currWordCount == wordCount) {
                        result.push_back(startIdx);

                        string leftWord = s.substr(startIdx,n);
                        currMap[leftWord]--;
                        currWordCount--;
                        startIdx += n;
                    }

                }
                else {

                    currMap.clear();
                    currWordCount = 0;
                    startIdx = j + n;
                }
            }
        }

        return result;
    }
};
