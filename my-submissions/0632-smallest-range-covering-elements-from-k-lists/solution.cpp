class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        // (element,listIdx,idx);

        int maxEle = INT_MIN;
        int maxEleIdx = 0;
        int maxEleListIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            int listIdx = i;
            int idx = 0;
            if (maxEle < element) {
                maxEle = element;
                maxEleIdx = idx;
                maxEleListIdx = listIdx;
            }
            pq.push({element, listIdx, idx});
        }

        vector<int> range = {pq.top()[0], maxEle};
        while (!pq.empty()) {
            auto op = pq.top();
            pq.pop();
            int minEle = op[0];
            int minEleListIdx = op[1];
            int minEleIdx = op[2];

            // go to the list and more idx forward for that list
            if (minEleIdx + 1 < nums[minEleListIdx].size()) {
                // we can move forward
                minEleIdx++;
                minEle = nums[minEleListIdx][minEleIdx];
                // update in pq;
                pq.push({minEle, minEleListIdx, minEleIdx});
            } else {
                break;
            }
            if (maxEle < minEle) {
                maxEle = minEle;
                maxEleIdx = minEleIdx;
                maxEleListIdx = minEleListIdx;
            }
            int currentMin = pq.top()[0];
            if (maxEle - currentMin < range[1] - range[0]) {
                range[0] = currentMin;
                range[1] = maxEle;
            }
        }

        return range;
    }
};
