class Solution {
public:
    int climbStairs(int num, vector<int>& prices) {
        prices.insert(prices.begin(), 0);
        const int LIMIT = INT_MAX / 2;
        vector<int> memo(num + 3, LIMIT);
        memo[num] = prices[num];
        for(int i = num - 1; i >= 0; --i){
            memo[i] = prices[i] + min({memo[i + 1] + 1, memo[i + 2] + 4, memo[i + 3] + 9});
        }
        return memo[0];
    }
};