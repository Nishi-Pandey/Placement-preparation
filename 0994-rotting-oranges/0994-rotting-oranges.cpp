#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int>> rottenQueue;
        
        // Step 1: Find all rotten oranges at minute 0 and add them to the queue
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        
        // Step 2: Start spreading the rotting process using BFS
        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();
            bool freshOranges = false;
            
            for (int i = 0; i < size; ++i) {
                int row = rottenQueue.front().first;
                int col = rottenQueue.front().second;
                rottenQueue.pop();
                
                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        rottenQueue.push({newRow, newCol});
                        freshOranges = true;
                    }
                }
            }
            
            if (freshOranges) {
                minutes++;
            }
        }
        
        // Step 3: Check if there are any fresh oranges left
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return minutes;
    }
};