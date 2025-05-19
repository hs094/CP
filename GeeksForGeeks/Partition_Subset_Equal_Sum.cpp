
class Solution {
  public:
    bool isSubsetSum(vector<int> &arr, int target) {
        vector<vector<int>> dp(arr.size()+1, vector<int> (target+1, 0));
        for(int i=0;i<=arr.size();i++) dp[i][0] = 1;
        for(int i=1;i<=arr.size();i++) {
            for(int j=1;j<=target;j++) {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[arr.size()][target];
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int i=0;i<arr.size();i++) sum += arr[i];
        if(sum % 2 != 0) return false;
        return isSubsetSum(arr, sum/2);
    }
};