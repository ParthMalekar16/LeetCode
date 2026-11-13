class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        long long ans = 0;
        int l = 0;
        long long sum_nums = 0;
        const long long INF = (1LL << 60);
        vector<long long> L_vals;
        int L_start = 0;
        vector<long long> L_max;
        vector<long long>L_sum; 
        vector<long long> R_vals;
        vector<pair<long long, long long>> R_segs;
        vector<long long> R_seg_vals;
        vector<long long> R_pref_cnt = {0};
        vector<long long> R_pref_sum = {0};
        for(int r = 0; r < n; ++r){
            long long x = nums[r];
            R_vals.push_back(x);
            if(R_segs.empty() || x > R_segs.back().first){
                R_segs.push_back({x, 1});
                long long prev_cnt = R_pref_cnt.back();
                long long prev_sum = R_pref_sum.back();
                R_pref_cnt.push_back(prev_cnt + 1);
                R_pref_sum.push_back(prev_sum + x);
                R_seg_vals.push_back(x);
            } 
            else{
                R_segs.back().second++;
                R_pref_cnt.back() += 1;
                R_pref_sum.back() += R_segs.back().first;
            }
            sum_nums += x;
            while(true){
                long long total_prefix = 0;
                long long maxLeft = -INF;
                if(L_start < (int)L_vals.size()){
                    total_prefix += L_sum[L_start];
                    maxLeft = L_max[L_start];
                }
                if(!R_segs.empty()){
                    if(maxLeft == -INF){
                        total_prefix += R_pref_sum.back();
                    } 
                    else{
                        int idx = upper_bound(R_seg_vals.begin(), R_seg_vals.end(), maxLeft) - R_seg_vals.begin();
                        long long cnt_before = R_pref_cnt[idx];
                        long long sum_before = maxLeft * cnt_before;
                        long long sum_after = R_pref_sum.back() - R_pref_sum[idx];
                        total_prefix += sum_before + sum_after;
                    }
                }
                long long cost = total_prefix - sum_nums;
                if(cost <= k){
                    break;
                }
                if(L_start == (int)L_vals.size()){
                    L_vals = R_vals;
                    L_start = 0;
                    int m = (int)L_vals.size();
                    L_max.assign(m, 0);
                    L_sum.assign(m, 0);
                    vector<pair<long long, long long>> st; 
                    long long current_sum = 0;
                    long long cur_max = -INF;
                    for(int i = m - 1; i >= 0; --i){
                        long long val = L_vals[i];
                        long long popped_count = 0;
                        while(!st.empty() && st.back().first <= val){
                            popped_count += st.back().second;
                            current_sum -= st.back().first * st.back().second;
                            st.pop_back();
                        }
                        long long cnt = 1 + popped_count;
                        st.push_back({val, cnt});
                        current_sum += val * cnt;
                        cur_max = max(cur_max, val);
                        L_sum[i] = current_sum;
                        L_max[i] = cur_max;
                    }
                    R_vals.clear();
                    R_segs.clear();
                    R_seg_vals.clear();
                    R_pref_cnt.assign(1, 0);
                    R_pref_sum.assign(1, 0);
                }
                sum_nums -= L_vals[L_start];
                ++L_start;
                ++l;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};