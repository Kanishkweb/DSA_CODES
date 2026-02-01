class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> bnk;
        for (int i = 0; i < bank.size(); i++) {
            bnk.insert(bank[i]);
        }
        if (bnk.find(endGene) == bnk.end())
            return -1;
        queue<string> q;
        q.push(startGene);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                if (curr == endGene)
                    return steps;
                q.pop();
                for (int i = 0; i < curr.length(); i++) {
                    for (auto& op : "ACGT") {
                        string newStr = curr;
                        newStr[i] = op;
                        if (bnk.find(newStr) != bnk.end()) {
                            bnk.erase(newStr);
                            q.push(newStr);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
