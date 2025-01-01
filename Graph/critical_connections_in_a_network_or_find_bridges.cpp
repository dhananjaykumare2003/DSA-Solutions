class Solution {
private:
    int timer = 1;
public:
    void dfs(int node,int parent,vector<int>& visited,vector<vector<int>>& adj,vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!visited[it]){
                dfs(it,node,visited,adj,tin,low,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,visited,adj,tin,low,bridges);
        return bridges;
    }
};
