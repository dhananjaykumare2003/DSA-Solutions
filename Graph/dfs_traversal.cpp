Time Complexity :- O(V+E)
Space Complexity :- O(V)
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& ans, vector<int>& visited){
        visited[node] = 1;
        ans.push_back(node);
        for(int it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,ans,visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n, 0);
        dfs(0,adj,ans,visited);
        return ans;
    }
};
