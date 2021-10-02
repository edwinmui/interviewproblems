class Solution {
public:
    int uniquePaths(int m, int n) {
        // edge cases
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        
        vector<vector<int>> memo;
        memo.resize(m, vector<int>(n));
        memo[m-1][n-1] = 1;
        for (int row = m-1; row >= 0; --row) {
            for (int col = n - 1; col >= 0; --col) {
                // ignore beginning tile
                if (row == m-1 && col == n-1) continue;
                // if on the edge of the board
                if (row == m-1){
                    memo[row][col] = memo[row][col+1];
                } 
                else if (col == n-1) {
                    memo[row][col] = memo[row+1][col];
                }
                else {
                    memo[row][col] = memo[row+1][col] + memo[row][col+1];
                }
            }
        }
        return memo[0][0];
    }
};
