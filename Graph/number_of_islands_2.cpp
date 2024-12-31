class DisjointSet{
    vector<int> rank,parent,sizeVec;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizeVec.resize(n+1,1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(sizeVec[ulp_u] < sizeVec[ulp_v]){
            parent[ulp_u] = ulp_v;
            sizeVec[ulp_v] += sizeVec[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            sizeVec[ulp_u] += sizeVec[ulp_v];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> visited(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        int cnt = 0;
        vector<int> ans;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(visited[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    if(visited[nrow][ncol] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = nrow * m + ncol;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
