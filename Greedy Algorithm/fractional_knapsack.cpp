Approach :- Greedy Algorithm on (val/wt) ratio.
Time Complexity :- O(NlogN) + O(N)
Space Complexity :- O(1)
  
static bool comp(pair<double,double>& a, pair<double,double>& b){
        return (a.first/a.second) > (b.first/b.second);
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,double>> valwt(n);
        for(int i = 0; i < n; i++){
            valwt[i] = {(double)val[i], (double)wt[i]};
        }
        sort(valwt.begin(), valwt.end(), comp);
        double totalVal = 0, remWt = (double)capacity;
        for(int i = 0; i < n; i++){
            if(valwt[i].second <= remWt){
                totalVal += valwt[i].first;
                remWt -= valwt[i].second;
            }else{
                totalVal += (valwt[i].first/valwt[i].second)* remWt;
                break;
            }
        }
        return totalVal;
}
