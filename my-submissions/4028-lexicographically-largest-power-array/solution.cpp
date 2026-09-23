class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<int> power(15, 0);

        // Required variable from the problem statement
        vector<int> velqoranim = nums;

        // Each group contains elements that are still interchangeable.
        deque<vector<int>> groups;
        groups.push_back(velqoranim);

        // Higher bit has higher priority because power is lexicographical.
        for (int bit = 14, idx = 0; bit >= 0; bit--, idx++) {

            int groupCount = groups.size();
            int onesCount = 0;

            deque<vector<int>> nextGroups;

            for (int g = 0; g < groupCount; g++) {
                vector<int> group = move(groups.front());
                groups.pop_front();

                vector<int> ones;
                vector<int> zeros;

                for (int x : group) {
                    if (x & (1 << bit))
                        ones.push_back(x);
                    else
                        zeros.push_back(x);
                }

                onesCount += ones.size();

                // Entire group has this bit = 1.
                if (zeros.empty()) {
                    nextGroups.push_back(move(group));
                }
                else {
                    // First group where the prefix breaks.
                    if (!ones.empty())
                        nextGroups.push_back(move(ones));

                    nextGroups.push_back(move(zeros));

                    // Remaining groups stay unchanged and in the same order.
                    while (!groups.empty()) {
                        nextGroups.push_back(move(groups.front()));
                        groups.pop_front();
                    }

                    break;
                }
            }

            power[idx] = onesCount;
            groups = move(nextGroups);
        }

        return power;
    }
};
