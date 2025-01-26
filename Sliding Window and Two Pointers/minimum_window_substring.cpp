Approach1:- Generating all subarrays
            To tackle the condition we stored cnt of t string elements earlier and then while traversing in s string we are reducing cnt of element in hash.
Time Complexity :- O(N^2*m)
Space Complexity :- O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int  minlen = 1e9, sindex = -1;
        for(int i = 0; i < n;i++){
            int hash[256] = {0};
            int cnt = 0;
            for(int j = 0; j < m; j++) hash[t[j]]++;
            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;
                if(cnt == m){
                    if(j-i+1 < minlen){
                        minlen = j-i+1;
                        sindex = i;
                        break;
                    }
                }
            }
        }
        return sindex == -1 ? "" : s.substr(sindex,minlen);
    }
};



Approach2:- Two pointer and sliding window
            To tackle the condition we stored cnt of t string elements earlier and then while traversing in s string we are reducing cnt of element in hash.
Time Complexity :- O(m+2n)
Space Complexity :- O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int hash[256] = {0};
        for(int i = 0; i < m; i++) hash[t[i]]++;
        int l = 0, r = 0, minlen = 1e9, cnt = 0,sindex = -1;
        while(r < n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                } 
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex,minlen);
    }
};
