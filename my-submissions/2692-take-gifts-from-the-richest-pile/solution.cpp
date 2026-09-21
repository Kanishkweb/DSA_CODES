class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto & gift : gifts){
            pq.push(gift);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            int newtop = floor(sqrt(top));
            pq.push(newtop);
        }
        int n = pq.size();
        long long result = 0;
        while(n--){
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
