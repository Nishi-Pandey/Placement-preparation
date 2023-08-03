class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // Ensure nums1 has smaller or equal length than nums2
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = m, partition1, partition2;
        int maxLeftX, maxLeftY, minRightX, minRightY;
        double median;
        
        while (left <= right) {
            partition1 = left + (right - left) / 2;
            partition2 = (m + n + 1) / 2 - partition1;
            
            maxLeftX = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            minRightX = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            maxLeftY = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            minRightY = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    median = (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    median = max(maxLeftX, maxLeftY);
                }
                break;
            } else if (maxLeftX > minRightY) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }
        
        return median;
    }
};
