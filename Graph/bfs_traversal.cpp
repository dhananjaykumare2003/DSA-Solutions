Time Complexity :- O(V+E)
Space Complexity :- O(V)
class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> ans;
        queue<pair<int,int>> q;
        vector<int> visited(n, 0);
        q.push({0,0});
        visited[0] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            ans.push_back(node);
            for(int it : adj[node]){
                if(!visited[it]){
                    q.push({it,dist+1});
                    visited[it] = 1;
                }
            }
        }
        return ans;
    }
};
