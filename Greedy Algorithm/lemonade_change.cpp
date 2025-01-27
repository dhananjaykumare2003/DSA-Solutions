Approach:- Greedy Algorithm because we will try to save smallest to largest currency in order to make all the payments.
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0, ten = 0, twenty = 0;
        for(int i = 0; i < n; i++){
            if(bills[i] == 5)five++;
            else if(bills[i] == 10){
                ten++;
                five--;
            }else{
                if(ten > 0){
                    ten--;
                    five--;
                }else{
                    five = five-3;
                }
            }
            if(five < 0) return false;
        }
        return true;
    }
};
