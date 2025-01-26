Approach-1:- brute force generating all subarrays and do according to given condition.
Time Complexity :- O(N^2*log(26)
Space Complexity :- O(26)

Approach2 :- two pointer and sliding window and using map to store cnt and to check k unique characters condition.
Time Complexity :- O(2Nlog(26)
Space Complexity :- O(26)
class Solution {
  public:
  
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int l = 0, r = 0, ans = -1;
        map<char,int> mpp;
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() == k) ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

Approach3 :- two pointer and sliding window with slight change, not reducing window less than maxlen when characters exceed k.
Time Complexity :- O(Nlog(26))
Space Complexity :- O(26)
class Solution {
  public:
  
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int l = 0, r = 0, ans = -1;
        map<char,int> mpp;
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() == k) ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
