Approach :- consider 4 variables left,right,top,bottom and perform as per the given condition and before submitting handle some edge cases
Time Complexity :- O(N*M)
Space Complexity :- O(N*M) {to store the answer}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l = 0,r = matrix[0].size()-1, t = 0, b = matrix.size()-1;
        while(l <= r && t <= b){
            for(int i = l; i <= r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i = t; i <= b; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t <= b){
                for(int i = r; i >= l; i--){
                ans.push_back(matrix[b][i]);
                }
                b--;
            }
            if(l <= r){
                for(int i = b; i >= t; i--){
                ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
