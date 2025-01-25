Approach1 :- generating all subarrays
Time Complexity :- O(N^2)
Space Complexity :- O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            set<char> st;
            for(int j = i; j < n; j++){
                st.insert(s[j]);
                if(st.size() == 3) ans++;
            }
        } 
        return ans;      
    }
};

Approach2:- using sliding window and two pointer
Time Complexity :- O(2*2N)
Space Complexity :- O(1)
class Solution {
public:
    int count(string s,int k){
        int n = s.size();
        int l = 0, r = 0, cnt = 0;
        map<char,int> mpp;
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() <= k){
                cnt += (r-l+1);
            }
            r++;
        }
        return cnt;
    }

    int numberOfSubstrings(string s) {
        return (count(s,3)-count(s,2));  
    }
};

Approach3:- using logical thinking
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lastseen[3] = {-1,-1,-1};
        int cnt = 0;
        for(int i = 0; i < n; i++){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt += 1 + min(lastseen[0],min(lastseen[1],lastseen[2]));
            }
        }  
        return cnt;
    }
};
