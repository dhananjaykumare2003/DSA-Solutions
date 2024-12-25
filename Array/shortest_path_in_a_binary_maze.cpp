class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        if(grid[0][0] == 1)return -1;
        dist[0][0] = 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {1,0,-1,-1,-1,0,1,1};
        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n 
                && grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis+1){
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            } 
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};
