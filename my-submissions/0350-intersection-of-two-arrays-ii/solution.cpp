class Solution {
public:
    int binarySearch(vector<int>& nums2, int start, int target) {
        // lower bound
        int end = nums2.size() - 1;
        int ans = -1;
        if (start > end)
            return ans;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums2[mid] >= target) {
                if (nums2[mid] == target)  ans =  mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // edge case
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        // binary search version
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // find the position
        int start = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];
            int pos = binarySearch(nums2, start, target);
            if (pos != -1) {
                result.push_back(target);
                start = pos + 1;
            }
        }
        return result;
    }
};
