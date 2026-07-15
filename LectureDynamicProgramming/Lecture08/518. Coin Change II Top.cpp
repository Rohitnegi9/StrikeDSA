class Solution {
public:

    int totalWays(int n, int amount, vector<int>& coins,vector<vector<int>>&dp){
         
         if(amount==0)
         return 1;

         if(n==0 || amount<0)
         return 0;

        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }


        return dp[n][amount] = totalWays(n-1,amount,coins,dp)+totalWays(n,amount-coins[n-1],coins,dp);
    }

    int change(int amount, vector<int>& coins) {
        // Your code here

        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        return totalWays(n,amount,coins,dp);
    }
};