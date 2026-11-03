class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        int maximumValue = *max_element(nums.begin(), nums.end());
        return (nums.size() * maximumValue) - totalSum;
    }
};