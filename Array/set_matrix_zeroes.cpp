Approach :- store rowindex and colindex in separate sets whenever we are getting "0"
Time Complexity :- O(M*N)
Space Complexity :- O(M+N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        unordered_set<int> str;
        unordered_set<int> stc;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    str.insert(i);
                    stc.insert(j);
                }
            }
        }
        for(int it:str){
            for(int i = 0; i < m; i++){
                matrix[it][i] = 0;
            }
        }
        for(int it:stc){
            for(int i = 0; i < n; i++){
                matrix[i][it] = 0;
            }
        }
    }
};

Approach :- storing rowindex and colindex in 0th row and col itself to reduce space but we need to handle the case of matrix[0][0]
Time Complexity :- O(M*N)
Space Complexity :- O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0) matrix[0][j] = 0;
                    else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
