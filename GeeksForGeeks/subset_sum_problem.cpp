
class Solution {
  public:
    bool solve(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
      if(sum==0){
          return 1;
      }
      if(i<0){
          return false;
      }
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
      bool take=false;
      if(sum>=arr[i]){
          take=solve(i-1,sum-arr[i],arr,dp);
      }
      bool nottake=solve(i-1,sum,arr,dp);
      dp[i][sum]=take || nottake;
      return dp[i][sum];
   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};