class Solution {
public:
    long long minimumCost(int val1, int val2, int valBoth, int target1, int target2) {
        long long price1 = val1, price2 = val2, priceBoth = valBoth;
        long long req1 = target1, req2 = target2;
        long long totalA = req1 * price1 + req2 * price2;
        long long common = min(req1, req2);
        long long totalB = common * priceBoth + (req1 - common) * price1 + (req2 - common) * price2;
        long long maximum = max(req1, req2);
        long long totalC = maximum * priceBoth;
        return min({totalA, totalB, totalC});
    }
};