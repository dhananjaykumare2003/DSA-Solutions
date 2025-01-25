Approach-1:- generating all subarrays
Time Complexity:- O(N^2)
Space Complexity :- O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int hash[26] = {0};
            int maxf = 0;
            for(int j = i; j < n; j++){
                hash[s[j]-'A']++;
                maxf = max(maxf, hash[s[j]-'A']);
                int changes = (j-i+1) - maxf;
                if(changes <= k) ans = max(ans, j-i+1);
                else break;
            }
        }
        return ans;
    }
};

Approach-2:- using two pointer and sliding window technique
Time Complexity:- O(2N*26)
Space Complexity :- O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0, maxf = 0;
        int hash[26] = {0};
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            while((r-l+1) - maxf > k){
                hash[s[l]-'A']--;
                maxf = 0;
                for(int i = 0; i < 26; i++){
                    maxf = max(maxf, hash[i]);
                }
                l++;
            }
            if((r-l+1) - maxf <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

Approach-3:- using two pointer and sliding window technique but in this solution we are not shrinking the window size to less than maxlen and 
also to reduce multipliy by 26 we don't use map because reduce maxlen or keeping it same doesn't have any effect.
Time Complexity:- O(N)
Space Complexity :- O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0, maxf = 0;
        int hash[26] = {0};
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            if((r-l+1) - maxf > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1) - maxf <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
