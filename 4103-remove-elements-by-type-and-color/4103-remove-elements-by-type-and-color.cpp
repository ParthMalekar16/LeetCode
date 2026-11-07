class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        struct Item{
            int t, c, cnt;
        };
        vector<Item> st;
        st.reserve(types.size());
        for(int i = 0; i < (int)types.size(); ++i){
            int t = types[i];
            int c = colors[i];
            int need = groupSize[t];
            if(!st.empty() && st.back().t == t && st.back().c == c){
                st.back().cnt = (st.back().cnt + 1) % need;
                if(st.back().cnt == 0){
                    st.pop_back();
                }
            }
            else{
                int cnt = 1 % need;
                if(cnt != 0){
                    st.push_back({t, c, cnt});
                }
            }
        }
        return st.empty();
    }
};