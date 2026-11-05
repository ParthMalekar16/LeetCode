class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distanceValueCount = 0;
        for(int num1 : arr1){
            bool isValid = true;
            for(int num2 : arr2){
                if(abs(num1 - num2) <= d){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                distanceValueCount++;
            }
        }
        return distanceValueCount;
    }
};