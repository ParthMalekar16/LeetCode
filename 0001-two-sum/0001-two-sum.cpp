class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexing;
        for (int i = 0; i < nums.size(); i++) {
            indexing.push_back({nums[i], i});
        }
        sort(indexing.begin(), indexing.end());
        int start = 0;
        int end = indexing.size() - 1;
        while(start < end){
            int sum = indexing[start].first + indexing[end].first;
            if(sum == target){
                return {indexing[start].second, indexing[end].second};
            } 
            else if(sum < target){
                start += 1;
            } 
            else{
                end -= 1;
            }
        }
        return {indexing[start].second, indexing[end].second};
    }
};