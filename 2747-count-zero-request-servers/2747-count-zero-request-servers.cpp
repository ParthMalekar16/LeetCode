class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        logs.push_back({0, 2000000000});
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> count(n + 1, 0);
        vector<int> ans(queries.size());
        int active = 0;
        int low = 0;
        int high = 0;
        for(int i = 0; i < sortedQueries.size(); i++){
            int q = sortedQueries[i].first;
            int idx = sortedQueries[i].second;
            while(high < logs.size() && logs[high][1] <= q){
                int server = logs[high][0];
                if(count[server] == 0){
                    active++;
                }
                count[server]++;
                high++;
            }
            while(low < logs.size() && logs[low][1] < q - x){
                int server = logs[low][0];
                count[server]--;
                if(count[server] == 0){
                    active--;
                }
                low++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};