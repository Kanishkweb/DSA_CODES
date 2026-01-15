class Trie {
public:
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode* root;
    Trie() { root = getNode(); }

    void insert(string word) {
        trieNode* start = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (start->children[c] == NULL) {
                start->children[c] = getNode();
            }
            start = start->children[c];
        }
        start->isEndOfWord = true;
    }

    bool search(string word) {
        trieNode* start = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (start->children[c] == NULL) {
                return false;
            }
            start = start->children[c];
        }
        if (start->isEndOfWord != 1) {
            return false;
        }
        return true;
    }

    bool startsWith(string prefix) {
        trieNode* start = root;
        for (char ch : prefix) {
            int c = ch - 'a';
            if (start->children[c] == NULL) {
                return false;
            }
            start = start->children[c];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
