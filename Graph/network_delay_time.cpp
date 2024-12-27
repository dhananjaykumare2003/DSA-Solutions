class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int dis = i.first;
            int node = i.second;
            for(auto iter : adj[node]){
                int v = iter.first;
                int wt = iter.second;
                if(dist[v] > dis+wt){
                    dist[v] = dis+wt;
                    pq.push({dis+wt,v});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i < n+1; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            else if(dist[i] > ans){
                ans = dist[i];
            }
        }
        return ans;
    }
};
