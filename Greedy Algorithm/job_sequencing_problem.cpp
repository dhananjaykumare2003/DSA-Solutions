Approach :- Greedy algorithm because we sort based on the profit and use the concept of delaying the deadline and use hash.
Time Complexity :- O(NlogN) + O(N) + O(md) + O(N*md) where md == maxdeadline.
Space Complexity :- O(3N) + O(md)
static bool comp(vector<int>& a, vector<int>& b){
        return a[2] > b[2];
    }
  
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n = id.size();
        vector<vector<int>> jobs(n);
        for(int i = 0; i < n; i++){
            jobs[i] = {id[i], deadline[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), comp);
        int maxdeadline = -1;
        for(int i = 0; i < n; i++){
            maxdeadline = max(maxdeadline, deadline[i]);
        }
        int hash[maxdeadline+1];
        for(int i = 0; i <= maxdeadline; i++){
            hash[i] = -1;
        }
        int cnt = 0, maxprofit = 0;
        for(int i = 0; i < n; i++){
            int dline = jobs[i][1];
            for(int j = dline; j > 0; j--){
                if(hash[j] == -1){
                    hash[j] = jobs[i][0];
                    cnt++;
                    maxprofit += jobs[i][2];
                    break;
                }
            }
        }
        return {cnt, maxprofit};
    }
