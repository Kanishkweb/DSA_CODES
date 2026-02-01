class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.length();

        set<string> wordLst;
        for (int i = 0; i < wordList.size(); i++) {
            wordLst.insert(wordList[i]);
        }
        if (wordLst.find(endWord) == wordLst.end())
            return 0;

        queue<string> q;
        q.push(beginWord); // mark visited;
        int path = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) {
                    return path;
                }
                for (int i = 0; i < curr.length(); i++) {
                    for (char op = 'a'; op <= 'z'; op++) {
                        if (op == curr[i])
                            continue;
                        string newStr = curr;
                        newStr[i] = op;
                        if (wordLst.find(newStr) != wordLst.end()) {
                            wordLst.erase(newStr);
                            q.push(newStr);
                        }
                    }
                }
            }
            path++;
        }
        return 0;
    }
};
