int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000,1e9);
        queue<pair<int,int>> q;
        q.push({0,start});
        dist[start] = 0;
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto it : arr){
                int mul = (node * it)%100000;
                if(dist[mul] > steps + 1){
                    dist[mul] = steps + 1;
                    if(mul == end) return dist[mul];
                    q.push({steps+1,mul});
                }
            }
        }
        if(dist[end] == 1e9)return -1;
        return dist[end];
    }
