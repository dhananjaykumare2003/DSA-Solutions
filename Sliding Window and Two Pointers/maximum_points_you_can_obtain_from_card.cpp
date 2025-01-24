Approach :- constant window (two pointer)
Time Complexity :- O(K)
Space Complexity :- O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int j = n-k,i = 0,sum = 0, maxSum = 0;
        for(int k = j; k < n; k++){
            sum += cardPoints[k];
        }
        maxSum = sum;
        while(j < n){
            sum -= cardPoints[j++];
            sum += cardPoints[i++];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
