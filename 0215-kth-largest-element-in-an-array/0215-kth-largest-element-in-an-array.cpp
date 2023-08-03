#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Create a min heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else {
                if (num > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }

        return minHeap.top();
    }
};