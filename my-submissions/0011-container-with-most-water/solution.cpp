class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1; // last index
        int maxArea = INT_MIN;
        while (i < j) {
            int area = 1;
            if (height[i] < height[j]) {
                area = (j - i) * height[i];
                i++;
            } else if (height[j] <= height[i]) {
                area = (j - i) * height[j];
                j--;
            }

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
