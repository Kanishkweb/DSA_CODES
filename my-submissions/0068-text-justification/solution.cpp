class Solution {
public:
    vector<string> result;
    void lastLine(vector<string>& words, int wordCount, int gap, int start) {
        string temp;
        int n = start + wordCount;
        int op = 1;
        if (wordCount == 1) {
            temp += words[start];
        } else {
            while (start < n) {
                temp += words[start];
                if(gap > 0){
                temp += " ";
                }
                gap--;
                start++;
            }
        }
        for (int i = 0; i < gap; i++) {
            temp += " ";
        }
        result.push_back(temp);
    }
    void addResult(vector<string>& words, int wordCount, double gap, int start) {
        string temp;
        int n = start + wordCount;
        if (wordCount == 1) {
            temp += words[start];
            for (int i = 0; i < gap; i++) {
                temp += " ";
            }
        } else {
            while (start < n) {
                temp += words[start];
                if (start == n - 1)
                    break;
                double gp = 0;
                gp = ceil(gap / (wordCount - 1));
                gap = gap - gp;
                wordCount--;
                for (int i = 0; i < gp; i++) {
                    temp += " ";
                }
                start++;
            }
        }
        result.push_back(temp);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordsSize = 0;
        int start = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (wordsSize + word.length() > maxWidth) {
                int wordCount = i - start;
                double gap = maxWidth - wordsSize + wordCount;
                addResult(words, wordCount, gap, start);
                start = i;
                wordsSize = 0;
            }
            wordsSize += word.length() + 1;
        }
        int wordCount = n - start;
        int gap = maxWidth - wordsSize + wordCount;
        lastLine(words, wordCount, gap, start);
        return result;
    }
};
