Approach :- Prims Algorithm
Time Complexity :- O(ElogE)
Space Complexity :- O(V)

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> visited(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node] == 1) continue;
            visited[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                    int v = it[0];
                    int vwt = it[1];
                    if(!visited[v]){
                        pq.push({vwt,v});
                    }
            }
            
        }
        return sum;
    }
};
