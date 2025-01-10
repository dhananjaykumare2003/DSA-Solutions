Approach :- BFS 
Time Complexity :- O(V+E)
Space Complexity :- O(2V)

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> visited(n,0);
        vector<int> ans(n,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        visited[src] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            ans[node] = dis;
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push({it,dis+1});
                }
            }
        }
        return ans;
    }
