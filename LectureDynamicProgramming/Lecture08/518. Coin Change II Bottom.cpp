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

    // dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
    //n = i == 0, 0
    //amount j ==0 , 1
    int change(int amount, vector<int>& coins) {
        // Your code here

        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        // first column ko fill kar do 1 se

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        // 0th row, oth column fill kar liya hai, initlize kar liya

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                dp[i][j] = dp[i-1][j];
            }
        }


        return dp[n][amount];
    }
};