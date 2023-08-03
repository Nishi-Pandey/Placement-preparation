#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Create a hashmap to count the frequencies of elements
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Create a priority queue (min heap) to keep track of k most frequent elements
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        
        for (auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            
            // Keep the size of the min heap to k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 3: Extract the top k frequent elements from the min heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        // Step 4: Reverse the result to get the k most frequent elements in descending order
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};