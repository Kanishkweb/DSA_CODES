class LRUCache {
public:
    class dll{
    public:
        dll* next = NULL;
        dll* prev = NULL;
        int key;
        int val;

        dll(int key,int val){
            this->key = key; 
            this->val = val;
        }
    };

    dll* root;
    dll* last;
    int cap;
    unordered_map<int,dll*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        root = new dll(-1,-1);
        last = new dll(-1,-1);

        root->next = last;
        last->prev = root;
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        dll* curr = mp[key];
        int val = curr->val;

        // remove node
        dll* oldCurr = curr->prev;
        dll* nextCurr = curr->next;

        oldCurr->next = nextCurr;
        nextCurr->prev = oldCurr;

        // add to last
        dll* oldNode = last->prev;

        oldNode->next = new dll(key,val);
        dll* newNode = oldNode->next;

        newNode->prev = oldNode;
        newNode->next = last;
        last->prev = newNode;

        mp[key] = newNode;

        return val;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){

            dll* currNode = mp[key];

            dll* oldNode = currNode->prev;
            dll* nextNode = currNode->next;

            oldNode->next = nextNode;
            nextNode->prev = oldNode;

            mp.erase(key);
        }

        dll* newNode = new dll(key,value);

        dll* oldNode = last->prev;

        oldNode->next = newNode;
        newNode->prev = oldNode;

        newNode->next = last;
        last->prev = newNode;

        mp[key] = newNode;

        if(mp.size() > cap){

            dll* lru = root->next;

            root->next = lru->next;
            lru->next->prev = root;

            mp.erase(lru->key);
        }
    }
};
