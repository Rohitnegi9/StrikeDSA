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

    // n = rows, = i
    // W = col = j
    // dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        // Code Here
        int n = wt.size();
         
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        // 0th row and Oth column sabko zero bana diya hai

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++){
                if(j-wt[i-1]>=0)
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
                else
                dp[i][j] = dp[i-1][j];
            }
        }


        return dp[n][W];
    }
};