#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;
class Solution {
public:
    
    /** This is the BFS solution **/
    // helper function
    void bfs(vector<vector<char>>& grid, int row, int col) {
        deque<pair<int, int>> q;
        q.push_back({row, col});
        while (!q.empty()) {
            pair<int, int> rowcol = q.front();
            q.pop_front();
            int row = rowcol.first;
            int col = rowcol.second;
            grid[row][col] = '0';
            // looks at spaces around current spot
            if (col < grid[0].size() - 1 && grid[row][col + 1] == '1') {
                q.push_back({row, col + 1});
                grid[row][col + 1] = '0';
            }
            if (row < grid.size() - 1 && grid[row+1][col] == '1') {
                q.push_back({row+1, col});
                grid[row+1][col] = '0';
            }
            if (col > 0 && grid[row][col - 1] == '1') {
                q.push_back({row, col - 1});
                grid[row][col - 1] = '0';
            }
            if (row > 0 && grid[row-1][col] == '1') {
                q.push_back({row - 1, col});
                grid[row - 1][col] = '0';
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // BFS
        // iterate through entire matrix
        // moment we hit a 1, do a breadth-first search on those around the 1
        // mark everything around it as 0 a.k.a sink it
        // after conducting bread-first search, increase one to num_islands
        int num_islands = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    bfs(grid, row, col);
                    num_islands += 1;
                }
            }
        }
        return num_islands;
    }
};
