class WordDictionary {
public:
    struct trieNode {
        bool isEnd = false;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode* root;
    WordDictionary() { root = getNode(); }

    void addWord(string word) {
        trieNode* start = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (start->children[c] == NULL) {
                start->children[c] = getNode();
            }
            start = start->children[c];
        }
        start->isEnd = true;
    }

    bool search(string word) {
        trieNode* start = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (start->children[j] != NULL) {
                        string w = word.substr(i + 1);
                        if (search(w, start->children[j])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int c = ch - 'a';
                if (start->children[c] == NULL) {
                    return false;
                }
                start = start->children[c];
            }
        }
        return start->isEnd;
    }
    bool search(string word, trieNode* node) {
        trieNode* start = node;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (start->children[j] != NULL) {
                        if (search(word.substr(i + 1), start->children[j])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int c = ch - 'a';
                if (start->children[c] == NULL) {
                    return false;
                }
                start = start->children[c];
            }
        }
        return start->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
