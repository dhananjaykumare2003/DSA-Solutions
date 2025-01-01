class Solution {
  public:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj,stack<int>& st){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
    void dfs2(int ind,vector<int>& visited,vector<vector<int>>& revadj){
        visited[ind] = 1;
        for(auto it : revadj[ind]){
            if(!visited[it]){
                dfs2(it,visited,revadj);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> visited(n,0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<vector<int>> revadj(n);
        for(int i = 0; i < n; i++){
            visited[i] = 0;
            for(auto it : adj[i]){
                revadj[it].push_back(i);
            }
        }
        int scc = 0; 
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                scc++;
                dfs2(node,visited,revadj);
            }
        }
        return scc;
    }
};
