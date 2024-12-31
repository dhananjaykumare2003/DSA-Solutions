class DisjointSet{
public:
    vector<int> rank,parent,sizeVec;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedges = 0;
        int cntComponents = 0;
        for(auto it : connections){
            if(ds.findUPar(it[0]) == ds.findUPar(it[1])){
                extraedges++;
            }else{
                ds.unionBySize(it[0],it[1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(i == ds.parent[i]){
                cntComponents++;
            }
        }
        int ans = cntComponents-1;
        if(extraedges >= ans){
            return ans;
        }
        else{
            return -1;
        }
    }
};
