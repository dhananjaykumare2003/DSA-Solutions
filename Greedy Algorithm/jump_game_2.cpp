Approach-1:- using recursion
Time Complexity :- O(N^N)
Space Complexity :- O(N)

Approach-2:- using range traversal
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int jumps = 0;
        while(r < n-1){
            int maxi = 0;
            while(l <= r){
                maxi = max(maxi, l + nums[l]);
                l++;
            }
            r = maxi;
            jumps++;
        }
        return jumps;
    }
};
