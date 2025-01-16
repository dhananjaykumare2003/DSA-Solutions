Approach 1:- Brute Force where for each element we will check can we get its consecutive greater numbers
Time Complexity :- O(N^2)
Space Complexity :- O(1)
class Solution {
public:
    bool ls(int x,vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1,cnt = 1;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1;
            while(ls(x + 1,nums) == true){
                x = x+1;
                cnt++;
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};

Approach- 2:- Better Approach, basic logic but check all the constraints carefully (n == 0 && n == 1 && for loop condition from 0 to n-1 not upto n && condition when numbers are same)
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

Approach 3:- using unordered_set
Time Complexity :- O(N)
Space Complexity :- O(N)
    
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int longest = 1;
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1,x = it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x = x+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
