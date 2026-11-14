class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX;
        for(int i = l; i <= r; i++){
            for(int j = 0; j + i <= n; j++){
                int totalSum = 0;
                for(int k = j; k < j + i; k++){
                    totalSum += nums[k];
                }  
                if(totalSum > 0 && totalSum < result){
                    result = totalSum;
                }    
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};