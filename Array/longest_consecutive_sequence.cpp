Approach :- basic logic but check all the constraints carefully (n == 0 && n == 1 && for loop condition from 0 to n-1 not upto n && condition when numbers are same)
Time Complexity :- O(NlogN) for sorting + O(N)
Space Complexity :- O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        sort(nums.begin(),nums.end());
        int maxcnt = 1, cnt = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] == nums[i] + 1){
                cnt++;
            }
            else if(nums[i+1] >= nums[i] + 2){
                cnt = 1;
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};
