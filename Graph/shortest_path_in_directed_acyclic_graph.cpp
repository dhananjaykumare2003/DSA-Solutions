Approach :- Dijkstra's Algorithm
TC :- O(ElogV)
Space Complexity :- O(V+E)

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    pq.push({dis+wt,v});
                    dist[v] = dis+wt;
                }
            }
        }
        int n = dist.size();
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
