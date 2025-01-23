Approach 1 :- Brute force counting each number from 1 to n
Time Complexity :- O(N^2)
Space Complexity :- O(1)

vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
       int repeating = -1, missing = -1;
       for(int i = 1; i <= n; i++){
           int cnt = 0;
           for(int j = 0; j < n; j++){
               if(arr[j] == i) cnt++;
           }
           if(cnt == 0) missing = i;
           else if(cnt == 2) repeating = i;
           if(missing != -1 && repeating != -1) break;
       }
       return {repeating,missing};
    }

Approach 2 :- sort, find duplicate, then find missing
Time Complexity :- O(NlogN) + O(2N)
Space Complexity :- O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int dup;
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]){
                dup = arr[i];
                break;
            }
        }
        int sum = 0, sumE = 0;
        for(int i = 0; i < n; i++){
            sum += i;
            sumE += arr[i];
        }
        sum += n;
        return {dup,(sum - sumE + dup)};
    }
};

Approach 3:- using hash array, store count of each number from 1 to N
Time Complexity :- O(2N)
Space Complexity :- O(N)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
       int hash[n+1] = {0};
       for(int i = 0; i < n; i++){
           hash[arr[i]]++;
       }
       int repeating = -1, missing = -1;
       for(int i = 1; i <= n; i++){
           if(hash[i] == 2) repeating = i;
           else if(hash[i] == 0) missing = i;
           
           if(repeating != -1 && missing != -1) break;
       }
       return {repeating,missing};
    }
};

Approach 4:- using maths
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       long long n = arr.size();
       long long sn = (n * (n+1))/2;
       long long s2n = (n * (n+1) * (2*n+1))/6;
       long long s = 0, s2 = 0;
       for(int i = 0; i<n; i++){
            s += arr[i];
            s2 += ((long long)arr[i] * (long long)arr[i]);
       }
       long long val1 = s-sn;//X-Y
       long long val2 = s2-s2n;
       val2 = val2/val1; //X+Y
       long long X = (val1 + val2)/2;
       long long Y = X-val1;
       return {(int)X, (int)Y};
    }
};

Approach 5 :- using xor 
  steps:- i> do xor of all the array elements along with 1 to N
          ii> find the differenciating bit in xr, first one from right side.
          iii> put them into two parts zero and one and xor them
          iv> by doing above step you will get missing and repeating number.
          v> but you need to count to clarify which one is missing or repeating.
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       long long n = arr.size();
       int xr = 0;
       for(int i = 0; i < n; i++){
           xr = xr ^ arr[i];
           xr = xr ^ (i+1);
       }
       int bitNo = 0;
       while(1){
           if((xr & (1 << bitNo)) != 0) break;
           bitNo++;
       }
       int zero = 0;
       int one = 0;
       for(int i = 0; i < n; i++){
           if((arr[i] & (1 << bitNo)) == 0){
               zero = zero ^ arr[i];
           }else{
               one = one ^ arr[i];
           }
       }
       for(int i = 1; i <= n; i++){
           if((i & (1 << bitNo)) == 0){
               zero = zero ^ i;
           }else{
               one = one ^ i;
           }
       }
       int cnt = 0;
       for(int i = 0; i < n; i++){
           if(arr[i] == one) cnt++;
       }
       if(cnt == 2) return {one,zero};
       return {zero,one};
       
    }
};
