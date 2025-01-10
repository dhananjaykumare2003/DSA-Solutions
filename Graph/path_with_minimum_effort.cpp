Approach :- Dijkstra's Algorithm in 2D array

int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto ii = pq.top();
            pq.pop();
            int dis = ii.first;
            int x = ii.second.first;
            int y = ii.second.second;
            for(int i = 0; i < 4; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int effort = max(dis,abs(heights[nrow][ncol] - heights[x][y]));
                    if(effort < dist[nrow][ncol]){
                        dist[nrow][ncol] = effort;
                        pq.push({effort,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
