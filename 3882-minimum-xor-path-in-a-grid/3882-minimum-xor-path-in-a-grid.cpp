class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bitset<1024>> dp(cols);
        dp[0][0] = 1;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bitset<1024> reach = dp[j];
                if(j > 0){
                    reach |= dp[j - 1];
                }
                dp[j].reset();
                for(int x = 0; x < 1024; x++){
                    if(reach[x]){
                        int newXor = x ^ grid[i][j];
                        dp[j][newXor] = 1;
                    }
                }
            }
        }
        int smallestXor = 0;
        while(smallestXor < 1024){
            if(dp[cols - 1][smallestXor]){
                return smallestXor;
            }
            smallestXor++;
        }
        return 0;
    }
};