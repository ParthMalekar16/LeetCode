class Solution {
public:
    long long countValidSubstrings(string s) {
        int lastA = -1;      
        int lastABStart = -1; 
        int maxStart = -1;   
        long long ans = 0;
        int n = (int)s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                lastA = i;
            }
            else if(s[i] == 'b'){
                if(lastA != -1){
                    lastABStart = max(lastABStart, lastA);
                }
            }
            else if(s[i] == 'c'){
                if(lastABStart != -1){
                    maxStart = max(maxStart, lastABStart);
                }
            }
            ans += (long long)i - maxStart;
        }
        return ans;
    }
};