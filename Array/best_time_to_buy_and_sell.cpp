Approach :- basic logic but most important thing to keep in mind that start from end of array and sell.
Time Complexity :- O(N)
Space Complexity :- O(1)
  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = prices[n-1],maxprofit = 0;
        for(int i = n-2; i >= 0; i--){
            if(prices[i] > sell){
                sell = prices[i];
            }else if(prices[i] <= sell){
                int profit = sell - prices[i];
                maxprofit = max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};
