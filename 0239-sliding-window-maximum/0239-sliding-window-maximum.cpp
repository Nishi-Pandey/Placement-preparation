#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements that are out of the current window from the front of the deque
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element from the back of the deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the back of the deque
            dq.push_back(i);

            // Once the window size reaches k, add the maximum element to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};