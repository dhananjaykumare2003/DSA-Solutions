Approach :- we will generate each row first, for that we will use the efficient way of finding nCr 
Time Complexity :- O(N^2)
Space Complexity :- O(1)
Concept :- to find particular element let say row = 5 and col = 3 we will use findnCr(row-1,col-1)
ii> optimised way of finding nCr
  int findnCr(int n,int r){
        int ans = 1;
        for(int i = 0; i < r; i++){
            ans = ans * (n-r);
            ans = ans/(i+1);
        }
        return ans;
    }

class Solution {
public:
    vector<int> generateRow(int r){
        int res = 1;
        vector<int> ans;
        ans.push_back(res);
        for(int i = 1; i < r; i++){
            res = res * (r-i);
            res = res/i;
            ans.push_back(res);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
