class Solution {
public:
    long long calculateIslandSum(vector<vector<int>>& grid, int row, int col) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rows = grid.size();
        int cols = grid[0].size();
        if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0){
            return 0;
        }
        long long currentSum = grid[row][col];
        grid[row][col] = 0;
        currentSum += calculateIslandSum(grid, row + 1, col);
        currentSum += calculateIslandSum(grid, row - 1, col);
        currentSum += calculateIslandSum(grid, row, col + 1);
        currentSum += calculateIslandSum(grid, row, col - 1);
        return currentSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] > 0){
                    long long totalSum = calculateIslandSum(grid, i, j);
                    if(totalSum % k == 0){
                        islandCount++;
                    }
                }
            }
        }
        return islandCount;
    }
};