class DisjointSet{
    vector<int> rank,parent,sizeVec;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizeVec.resize(n+1,1);
        for(int i = 0; i <= n; i++){
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0,maxCol = 0,n = stones.size();
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> mpp;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow,nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it : mpp){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};
