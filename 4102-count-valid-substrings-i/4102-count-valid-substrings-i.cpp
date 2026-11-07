class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int lastStart = -1;
        for(int i = 0; i < n; i++){
            if(i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c'){
                lastStart = i - 2;
            }
            ans += i - lastStart;
        }
        return ans;
    }
};