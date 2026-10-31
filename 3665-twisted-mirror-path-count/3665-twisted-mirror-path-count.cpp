class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        const int MOD = 1e9 + 7;
        int numCols = grid[0].size();
        vector<int> waysFromAbove(numCols, 0);
        waysFromAbove[0] = 1;
        for(auto& currentRow : grid){
            int waysFromLeft = 0;
            for(int col = 0; col < numCols; col++){
                if(currentRow[col] != 0){
                    swap(waysFromLeft, waysFromAbove[col]);
                }
                else{
                    long long totalWays = (long long)waysFromLeft + waysFromAbove[col];
                    totalWays = totalWays % MOD;
                    waysFromLeft = totalWays;
                    waysFromAbove[col] = totalWays;
                }
            }
        }
        return waysFromAbove.back();
    }
};