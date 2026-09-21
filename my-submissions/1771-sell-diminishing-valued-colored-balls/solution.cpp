class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<int> pq;

        for (auto& color : inventory) {
            pq.push(color);
        }

        long long answer = 0;
        int MOD = 1e9 + 7;

        while (orders > 0) {
            int y = pq.top();
            pq.pop();

            int count = 1;

            // count how many same maximum values
            while (!pq.empty() && pq.top() == y) {
                pq.pop();
                count++;
            }

            int x = 0;
            if (!pq.empty()) {
                x = pq.top();
            }

            long long term = 1LL * count * (y - x);

            if (orders >= term) {

                // sum: y + (y-1) + ... + (x+1)
                long long sum = 1LL * (y - x) * (y + x + 1) / 2;

                answer = (answer + (1LL * count * (sum % MOD)) % MOD) % MOD;

                orders -= term;

                // push x back for every color
                for (int i = 0; i < count; i++) {
                    if (x > 0)
                        pq.push(x);
                }

            } else {

                long long full = orders / count;
                long long rem = orders % count;

                // sell: y, y-1, ... for 'full' levels
                long long newY = y - full;

                long long sum = 1LL * full * (y + newY + 1) / 2;

                answer = (answer + (1LL * count * (sum % MOD)) % MOD) % MOD;

                // remaining orders take the newY value
                answer = (answer + (rem * newY) % MOD) % MOD;

                orders = 0;
            }
        }

        return answer;
    }
};
