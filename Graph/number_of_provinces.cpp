Approach :- Connnected Components concept
Time Complexity :- O(N^2)
Space Complexity :- O(N^2)
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&visited){
        visited[node] = 1;
        for(int it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                cnt++;
            }   
        }
        return cnt;
    }
};
