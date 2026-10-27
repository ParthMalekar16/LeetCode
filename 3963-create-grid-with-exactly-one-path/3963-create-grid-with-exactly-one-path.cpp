class Solution {
public:
    vector<string> createGrid(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> grid(m, string(n, '#'));
        int currentRow = 0;
        int currentCol = 0;
        grid[currentRow][currentCol] = '.';
        while(currentRow < m - 1 || currentCol < n - 1){
            bool moveDown = false;
            if(currentRow < m - 1){
                if(currentCol == n - 1){
                    moveDown = true;
                }
                else{
                    int diffIfDown = abs((currentRow + 1) * (n - 1) - currentCol * (m - 1));
                    int diffIfRight = abs(currentRow * (n - 1) - (currentCol + 1) * (m - 1));
                    if(diffIfDown <= diffIfRight){
                        moveDown = true;
                    }
                }
            }
            if(moveDown){
                currentRow++;
            }
            else{
                currentCol++;
            }
            grid[currentRow][currentCol] = '.';
        }
        return grid;
    }
};