class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // step - 1
        vector<int> result;
        int i = 0;
        int j = numbers.size() - 1; // last index;
        while (i < j) {
            // three conditions;
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] == target) {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
        }
        return result;
    }
};
