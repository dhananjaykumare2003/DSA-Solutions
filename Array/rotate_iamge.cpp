Approach :- To rotate by 90 degree, first transpose that matrix and then reverse the array
Time Complexity :- O(N*M)
Space Complexity :- O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i < j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int s = 0, e = m-1;
            while(s < e){
                swap(matrix[i][s],matrix[i][e]);
                s++;
                e--;
            }
        }
    }
};
