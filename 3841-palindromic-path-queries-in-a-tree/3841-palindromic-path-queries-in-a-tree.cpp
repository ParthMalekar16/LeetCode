class Solution {
public:
    int totalNodes;
    vector<int> bitree;
    void add(int index, int value) {
        for(; index <= totalNodes + 1; index += index & -index){
            bitree[index] ^= value;
        }
    }
    int get(int index) {
        int result = 0;
        for(; index > 0; index -= index & -index){
            result ^= bitree[index];
        }
        return result;
    }
    void rangeXor(int left, int right, int value) {
        add(left, value);
        add(right + 1, value);
    }
    int getLca(int u, int v, const vector<vector<int>>& up, const vector<int>& depth, int logLimit) {
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int j = 0; j < logLimit; j++){
            if((diff >> j) & 1){
                u = up[j][u];
            }
        }
        if(u == v){
            return u;
        }
        for(int j = logLimit - 1; j >= 0; j--){
            if(up[j][u] != up[j][v]){
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        totalNodes = n;
        bitree.assign(n + 2, 0);
        vector<vector<int>> adjacencyList(n);
        for(auto& edge : edges){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        int logLimit = 1;
        while((1 << logLimit) < n){
            logLimit++;
        }
        vector<vector<int>> up(logLimit, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<int> tin(n, 0);
        vector<int> tout(n, 0);
        vector<int> iteratorIndex(n, 0);
        vector<int> stack;
        int timer = 1;
        stack.push_back(0);
        tin[0] = 1;
        while(!stack.empty()){
            int u = stack.back();
            if(iteratorIndex[u] < (int)adjacencyList[u].size()){
                int v = adjacencyList[u][iteratorIndex[u]++];
                if(v == up[0][u]){
                    continue;
                }
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = ++timer;
                stack.push_back(v);
            }
            else{
                tout[u] = timer;
                stack.pop_back();
            }
        }
        for(int j = 1; j < logLimit; j++){
            for(int v = 0; v < n; v++) {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }
        for(int u = 0; u < n; u++){
            rangeXor(tin[u], tout[u], 1 << (s[u] - 'a'));
        }
        vector<bool> result;
        for(auto& query : queries){
            istringstream stream(query);
            string type;
            stream >> type;
            if(type == "update"){
                int u;
                char c;
                stream >> u >> c;
                if(s[u] != c){
                    int maskDiff = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                    rangeXor(tin[u], tout[u], maskDiff);
                    s[u] = c;
                }
            }
            else{
                int u, v;
                stream >> u >> v;
                int lcaNode = getLca(u, v, up, depth, logLimit);
                int pathXor = get(tin[u]) ^ get(tin[v]) ^ (1 << (s[lcaNode] - 'a'));
                result.push_back((pathXor & (pathXor - 1)) == 0);
            }
        }
        return result;
    }
};