Approach-1:- Recursion trying out all possible ways
Time Complexity :- O(3^N)
Space Complexity :- O(N)
class Solution {
public:
    bool check(int ind,string s, int cnt,int n){
        if(cnt < 0) return false;
        if(ind == n) return cnt == 0;
        
        if(s[ind] == '(') return check(ind+1,s,cnt+1,n);
        if(s[ind] == ')') return check(ind+1,s,cnt-1,n);
        return check(ind+1,s,cnt+1,n) || check(ind+1,s,cnt-1,n) || check(ind+1,s,cnt,n);
    }

    bool checkValidString(string s) {
        int n = s.size();
        int index = 0, cnt = 0;
        return check(index, s, cnt, n);
    }
};

Approach-2 :- creative thinking
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min = 0, max = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                min = min + 1;
                max = max + 1;
            }else if(s[i] == ')'){
                min = min - 1;
                max = max - 1;
            }else{
                min = min - 1;
                max = max + 1;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }
};
