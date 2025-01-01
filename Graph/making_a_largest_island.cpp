class DisjointSet{
public:
    vector<int> rank,parent,sizeVec;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizeVec.resize(n+1,1);
        for(int i = 0; i < n+1; i++){
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

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n*n);
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        //step-1
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 1){
                        int nodeNo = i * n + j;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        //step-2
        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                set<int> components;
                for(int i = 0; i < 4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n){
                        if(grid[nrow][ncol] == 1){
                            components.insert(ds.findUPar(nrow*n+ncol));
                        }
                    }
                }
                int setTotal = 0;
                for(auto it : components){
                    setTotal += ds.sizeVec[it];
                }
                mx = max(mx,setTotal + 1);
            }
        }
        for(int cellNo = 0; cellNo < n*n; cellNo++){
            mx = max(mx,ds.sizeVec[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
