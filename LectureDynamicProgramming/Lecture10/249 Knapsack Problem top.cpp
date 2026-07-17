class Solution {
  public:
    
    int findMaxVal(int n, int W, vector<int>&val, vector<int>&wt,vector<vector<int>>&dp){
        
        if(W<0){
            return INT_MIN;
        }

        if(n==0 || W==0)
        return 0;
        
        if(dp[n][W]!=-1)
        return dp[n][W];


        return dp[n][W] = max(findMaxVal(n-1,W,val,wt,dp), val[n-1]+findMaxVal(n-1,W-wt[n-1],val,wt,dp));
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        // Code Here
        int n = wt.size();
         
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return findMaxVal(n,W,val,wt,dp);
    }
};