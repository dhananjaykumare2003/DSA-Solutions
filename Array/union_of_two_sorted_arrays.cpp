Approach :- Two Pointer
TC :- O(N+M)
SC :- O(N+M)

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> tempa;
        vector<int> tempb;
        tempa.push_back(a[0]);
        tempb.push_back(b[0]);
        for(int i = 1; i < n; i++){
            if(a[i] > a[i-1]){
                tempa.push_back(a[i]);
            }
        }
        for(int i = 1; i < m; i++){
            if(b[i] > b[i-1]){
                tempb.push_back(b[i]);
            }
        }
        n = tempa.size(),m = tempb.size();
        int i = 0,j = 0;
        vector<int> ans;
        while(i < n && j < m){
            if(tempa[i] < tempb[j]){
                ans.push_back(tempa[i++]);
            }else if(tempa[i] > tempb[j]){
                ans.push_back(tempb[j++]);
            }else{
                ans.push_back(tempa[i++]);
                j++;
            }
        }
        while(i < n){
            ans.push_back(tempa[i++]);
        }
        while(j < m){
            ans.push_back(tempb[j++]);
        }
        return ans;
    }
};

Approach :- Using Set
TC :- O(N+M)
SC :- O(N+M)
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(),m = b.size();
        set<int> st;
        vector<int> ans;
        for(int i = 0; i < n; i++) st.insert(a[i]);
        for(int i = 0; i < m; i++) st.insert(b[i]);
        for(int it : st){
            ans.push_back(it);
        }
        return ans;
    }
};

Approach :- Two Pointer
TC :- O(N+M)
SC :- O(1)
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        int i = 0,j = 0;
        vector<int> ans;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                if(ans.size() == 0 || ans.back() != a[i]){
                    ans.push_back(a[i]); 
                }
            i++;
            }else{
                if(ans.size() == 0 || ans.back() != b[j]){
                    ans.push_back(b[j]);  
                }
            j++;
            }
        }
        while(i < n){
            if(ans.size() == 0 || ans.back() != a[i]){
                ans.push_back(a[i]); 
            }
            i++;
        }
        while(j < m){
            if(ans.size() == 0 || ans.back() != b[j]){
                ans.push_back(b[j]);  
            }
            j++;
        }
        return ans;
    }
};
