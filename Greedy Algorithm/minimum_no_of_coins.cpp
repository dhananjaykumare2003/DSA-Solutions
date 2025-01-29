Approach :- Greedy Algorithm as we considering maximum value coins first.
Time Complexity :- O(N) approx.
Space Complexity :- O(N)
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> currency = {2000,500,200,100,50,20,10,5,2,1};
        int n = currency.size();
        for(int i = 0; i < n; i++){
            if(N == 0) break;
            while(N >= currency[i]){
                ans.push_back(currency[i]);
                N = N - currency[i];
            }
        }
        return ans;
    }
};
