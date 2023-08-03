class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int i = left;
        int j = mid + 1;

        // Count the reverse pairs
        while (i <= mid && j <= right) {
            if ((long long)nums[i] > 2 * (long long)nums[j]) {
                count += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }

        // Merge two sorted halves
        vector<int> temp(right - left + 1);
        int k = 0;
        i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }

        return count;
    }
};
