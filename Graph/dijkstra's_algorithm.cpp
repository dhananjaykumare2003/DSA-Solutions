Approach :- dijkstra's algorithm 
            i>used dist[] array with initial distance infinity and priority queue.
            ii> if(dist+wt) of adjacent node is less than dist[adjnode] then we will replace it by dis+wt.
Time Complexity :- O(ElogV)
Space Complexity :- O(V)
class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis+wt;
                    pq.push({dis+wt,v});
                }
            }
        }
        return dist;
    }
};
