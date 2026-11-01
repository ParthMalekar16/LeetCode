class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimumValue = ranges::min(nums);
        int totalMoves = 0;
        for(int x : nums){
            totalMoves += x - minimumValue;
        }
        return totalMoves;
    }
};