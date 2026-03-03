class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // always binary search in smaller array
        if(n1 > n2){
            return findMedianSortedArrays(nums2,nums1);
        }

        // edge case
        if (n1 == 0 && n2 == 0) {
            return 0.0;
        }
        int teils = 0;
        if ((n1 + n2) % 2 == 0) { // even
            teils = (n1 + n2) / 2;
        } else { // odd
            teils = (n1 + n2 + 1) / 2;
        }
        // binary search
        int start = 0;
        int end = n1;
        double median = 0.0;
        while (start <= end) {
            int mid1 = start + (end - start) / 2;
            int mid2 = teils - mid1; // for better indexing
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 - 1 >= 0) {
                l1 = nums1[mid1 - 1];
            }
            if (mid1 < n1) {
                r1 = nums1[mid1];
            }
            if (mid2 - 1 >= 0) {
                l2 = nums2[mid2 - 1];
            }
            if (mid2 < n2) {
                r2 = nums2[mid2];
            }
            // now check for symmetry
            if (l1 <= r2 && l2 <= r1) {
                // calc median according to even and odd
                if ((n1 + n2) % 2 == 0) {

                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                end = mid1 - 1;
            } else {
                start = mid1 + 1;
            }
        }
        return median;
    }
};
