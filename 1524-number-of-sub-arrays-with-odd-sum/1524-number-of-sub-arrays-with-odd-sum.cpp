class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        static constexpr int MOD = 1'000'000'007;
        long long evenCount = 1; 
        long long oddCount = 0;
        int parity = 0;
        long long ans = 0;
        for(int x : arr){
            parity ^= ((x % 2) + 2) % 2;
            if(parity == 1){
                ans += evenCount;
                ++oddCount;
            }
            else{
                ans += oddCount;
                ++evenCount;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};