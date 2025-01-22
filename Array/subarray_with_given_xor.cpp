Approach 1:- genearating all subarray and checking
Time Complexity :- O(N^3) which boils down to O(N^2) 
Space Complexity :- O(1)

Approach 2:- using hashmap similar concept as prefixsum 
Time Complexity :- O(NlogN) 
Space Complexity :- O(N)

int Solution::solve(vector<int> &A, int B) {
    int n1 = A.size();
    map<int,int> mpp;
    int cnt = 0;
    int xr = 0;
    mpp[0] = 1;
    for(int i = 0; i < n1; i++){
        xr = xr ^ A[i];
        int x = xr ^ B;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
