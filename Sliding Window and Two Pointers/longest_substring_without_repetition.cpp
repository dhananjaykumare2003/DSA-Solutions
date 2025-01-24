Approach :- generating all the subarrays and using hash to check repetitions
Time Complexity :- O(N^2)
Space Complexity :- O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            for(int j = i; j < n; j++){
                if(hash[s[j]] == 1) break;
                int len = j-i+1;
                ans = max(ans,len);
                hash[s[j]] = 1;
            }
        }
        return ans;
    }
};

Approach :- two pointers and sliding window, using hash to check repetitions
Time Complexity :- O(N)
Space Complexity :- O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int hash[256];
        for(int i = 0; i < 256; i++){
            hash[i] = -1;
        }
        int maxlen = 0;
        while(r < n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
            maxlen = max(maxlen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
