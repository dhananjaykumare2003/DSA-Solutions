Approach-1 :- using hashMap to store the count of each numbers.
Time Complexity :- O(NlogN)
Space Complexity :- O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > (n/3) && (ans.size() == 0 || ans[0] != nums[i])){
                ans.push_back(nums[i]);
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};


Approach-2 :- a concept which says only two elements are possible to do so, we use the same concept as of majority_element 1 ( > N/2) with two counters.
Time Complexity :- O(N)
Space Complexity :- O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            } 
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i])cnt1++;
            else if(el2 == nums[i])cnt2++;
            else{
                cnt1--,cnt2--;
            }
        }
        //confirmation check
        cnt1 = 0,cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(el1 == nums[i])cnt1++;
            if(el2 == nums[i])cnt2++;
        }
        if(cnt1 > (n/3)) ans.push_back(el1);
        if(cnt2 > (n/3)) ans.push_back(el2);
        return ans;
    }
};
