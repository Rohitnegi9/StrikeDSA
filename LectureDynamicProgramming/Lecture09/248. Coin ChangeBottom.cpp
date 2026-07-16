class Solution {
public:

    int findMinCoin(int n, int amount, vector<int>&coins,vector<vector<int>>&dp){
        
        if(amount==0)
        return 0;

        if(n==0 || amount<0)
        return 1e9;
       
       if(dp[n][amount]!=-1)
       return dp[n][amount];

       return dp[n][amount] = min(findMinCoin(n-1,amount,coins,dp), 1+findMinCoin(n,amount-coins[n-1],coins,dp));
    }

    // dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);

    // n = row, i
    // amount, column, j

    int coinChange(vector<int>& coins, int amount) {
        // Your code here
         int n = coins.size();
         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
         // zero row ko initlize kar do , 1e9
         // zero column ko initlize kar do zero se

         for(int j=0;j<=amount;j++)
         dp[0][j] = 1e9;



         for(int i=0;i<=n;i++){
            dp[i][0] = 0;
         }


         for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                else
                dp[i][j] = dp[i-1][j];
            }
         }


         // dp[n][amount]

         return dp[n][amount]>=1e9 ? -1: dp[n][amount];


        
    }
};