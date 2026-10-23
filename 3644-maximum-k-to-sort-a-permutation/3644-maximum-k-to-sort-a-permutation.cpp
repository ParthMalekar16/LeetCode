class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = nums.size();
        int bitwiseAndResult = -1;
        for(int i = 0; i < size; i++){
            if(nums[i] != i){
                if(bitwiseAndResult == -1){
                    bitwiseAndResult = nums[i];
                }
                else{
                    bitwiseAndResult &= nums[i];
                }
            }
        }
        if(bitwiseAndResult == -1){
            return 0;
        }
        return bitwiseAndResult;
    }
};