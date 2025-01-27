Approach :- Greedy Algorithm because we are sorting or taking end time which are smaller first.
Time Complexity :- O(NlogN) + O(N)
Space Complexity :- O(2N)
int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> pairs(n);
        for(int i = 0; i < n; i++){
            pairs[i] = {end[i],start[i]};
        }
        sort(pairs.begin(),pairs.end());
        int endTime = pairs[0].first;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(pairs[i].second > endTime){
                cnt++;
                endTime = pairs[i].first;
            } 
        }
        return cnt;
    }
