class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<pair<int, int>>> adjacencyList(n);
        for(auto& edge : edges){
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
        }
        vector<int> shortestRun(n, k + 1);
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<>> priorityQueue;
        priorityQueue.emplace(0, 1, 0);
        while(!priorityQueue.empty()){
            auto [currentDistance, currentRun, currentNode] = priorityQueue.top();
            priorityQueue.pop();
            if(currentRun >= shortestRun[currentNode]){
                continue;
            }
            if(currentNode == n - 1){
                return currentDistance;
            }
            shortestRun[currentNode] = currentRun;
            for(auto [neighborNode, edgeWeight] : adjacencyList[currentNode]){
                int nextRun = 1;
                if(labels[neighborNode] == labels[currentNode]){
                    nextRun = currentRun + 1;
                }
                if(nextRun < shortestRun[neighborNode]){
                    priorityQueue.emplace(currentDistance + edgeWeight, nextRun, neighborNode);
                }
            }
        }
        return -1;
    }
};