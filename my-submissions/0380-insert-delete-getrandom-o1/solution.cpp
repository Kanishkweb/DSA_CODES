class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            arr.push_back(val);
            mp.insert({val, arr.size()});
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
            int idx = mp[val]-1;
            int temp = arr[arr.size() - 1]; // lastEle
            arr[idx] = temp; 
            mp[arr[idx]] = idx+1;
            arr.pop_back();
            mp.erase(val);
            return true;
        } else { 
            return false;
        }
    }

    int getRandom() {
        int n = arr.size();
        int i = rand() % n;
        return arr[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
