class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> count(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        count[0] = 1;
        int mod = (1e9 + 7);
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            long long dis = i.first;
            int node = i.second;
            if(dis > dist[node]) continue;
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                long long disSum = (dis+wt);
                if(dist[v] > disSum){
                    dist[v] = disSum;
                    pq.push({disSum,v});
                    count[v] =  count[node];
                }
                else if(dist[v] == disSum){
                    count[v] = (count[v] + count[node])%mod;
                }
            }
        }
        return count[n-1];
    }
};
