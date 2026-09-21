class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int res = y - x;
            if(res != 0){
                pq.push(res);
            }
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};
