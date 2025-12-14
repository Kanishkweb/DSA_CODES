class Solution {
public:
    int solve(vector<int>& gas, vector<int>& cost, int stIdx) {
        int n = gas.size();
        int i = stIdx;
        int gasTank = gas[stIdx];
        int costIdx = i;
        int refilGas = i + 1;
        while (stIdx != refilGas % n) {
            if (gasTank - cost[costIdx % n] <= 0) {
                return 0; // false
            }
            gasTank = gasTank - cost[costIdx % n] + gas[refilGas % n];
            costIdx++;
            refilGas++;
        }
        gasTank = gasTank - cost[costIdx % n];
        if (gasTank < 0) {
            return 0; // false
        }
        return 1; // true
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] >= cost[i]) {
                if (solve(gas, cost, i)) {
                    return i;
                }
            }
        }
        return -1;
    }
};
