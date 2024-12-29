int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                int wt = it[1];
                int adjNode = it[0];
                int node = i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstwt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
