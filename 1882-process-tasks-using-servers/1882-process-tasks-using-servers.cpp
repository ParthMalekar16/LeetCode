class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        struct Busy{
            long long finish;
            int weight;
            int index;
        };
        struct BusyCmp {
            bool operator()(const Busy& a, const Busy& b) const {
                if(a.finish != b.finish){
                    return a.finish > b.finish;
                }
                if(a.weight != b.weight){
                    return a.weight > b.weight;
                }
                else{
                    return a.index > b.index;
                } 
            }
        };
        priority_queue<Busy, vector<Busy>, BusyCmp> busyServers;
        for(int i = 0; i < n; ++i){
            freeServers.push({servers[i], i});
        }
        for(int s = 0; s < m; ++s){
            while(!busyServers.empty() && busyServers.top().finish <= s){
                Busy b = busyServers.top();
                busyServers.pop();
                freeServers.push({b.weight, b.index});
            }
            if(!freeServers.empty()){
                pair<int, int> top = freeServers.top();
                freeServers.pop();
                int w = top.first;
                int idx = top.second;
                long long finish = (long long)s + tasks[s];
                busyServers.push({finish, w, idx});
                ans[s] = idx;
            } 
            else{
                Busy b = busyServers.top();
                busyServers.pop();
                long long start = b.finish;
                long long finish = start + tasks[s];
                busyServers.push({finish, b.weight, b.index});
                ans[s] = b.index;
            }
        }
        return ans;
    }
};