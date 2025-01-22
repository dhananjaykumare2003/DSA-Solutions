Approach :- logic based on question
Time Complexity :- O(NlogN) + O(N)
Space Complexity :- O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int startTime = intervals[0][0], endTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= endTime){
                endTime = max(endTime, intervals[i][1]);
            }else{
                ans.push_back({startTime,endTime});
                startTime = intervals[i][0];
                endTime = intervals[i][1];
            }
        }
        ans.push_back({startTime, endTime});
        return ans;
    }
};
