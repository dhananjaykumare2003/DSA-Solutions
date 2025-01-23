Approach-1:- generating all subarrays and finding maxproduct among them
Time Complexity :- O(N^2)
Space Complexity :- O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans =INT_MIN;
        for(int i = 0; i < n; i++){
            int prd = 1;
            for(int j = i; j < n; j++){
                prd *= nums[j];
                ans = max(ans,prd);  
            }
        }  
        return ans; 
    }
};

Approach-2:- using prefix and suffix logic based on observation
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1;//prefix and suffix
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre*nums[i];
            suff = suff*nums[n-1-i];
            ans = max(ans,max(pre,suff));
        }
        return ans;
    }
};
