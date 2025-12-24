class Solution {
public:
    int leftToRight(vector<int>& height, int n) {
        int total = 0;
        int leftMax = height[0];
        for (int i = 1; i <= n; i++) {
            if (leftMax < height[i]) {
                leftMax = height[i];
            } else {
                total += leftMax - height[i];
            }
        }
        return total;
    }
    int rightToLeft(vector<int>& height, int n, int end) {
        int total = 0;
        int rightMax = height[n];
        for (int i = n - 1; i >= end; i--) {
            if (rightMax < height[i]) {
                rightMax = height[i];
            } else {
                total += rightMax - height[i];
            }
        }
        return total;
    }
    int trap(vector<int>& height) {
        int n = height.size() - 1;
        int start = 0;
        int result = 0;
        int mid = 0;
        int midIndex = 0;
        for (int i = 0; i < height.size(); i++) {
            if(mid < height[i]){
                mid = height[i];
                midIndex = i;
            }
        }
        cout << midIndex << endl;
        if (height[start] <= mid || mid > height[n]) {
            result = leftToRight(height, midIndex) + rightToLeft(height, n, midIndex);
        }
        return result;
    }
};
