Approach Steps :- 1> Initialise dist[] array 
                  2> perform relaxation of all nodes by performing for loop for n-1 times through all the edges
Time Complexity :- O(V*E)
Space Complexity :- O(V)

//Code:-
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i = 0; i < V-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                } 
            }
        }
        //check for negative edge cycle
        for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                } 
        }
        return dist;
    }
