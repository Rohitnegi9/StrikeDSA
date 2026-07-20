int maximumProfit(int index, int buy, int transaction, int n, vector<int>&prices,vector<vector<vector<int>>>&dp){

    if(transaction==0 || index==n){
        return 0;
    };

   if(dp[index][buy][transaction]!=-1)
   return dp[index][buy][transaction];

    //
    if(buy){
        
        // Either I can buy the stock or I will not buy the stock

    return dp[index][buy][transaction] =  max( -prices[index]+maximumProfit(index+1,0,transaction,n,prices,dp),
        maximumProfit(index+1,1,transaction,n,prices,dp));

    }
    else{
         
         // Eithr I can sell the stock today or I will sell the stock today

         return dp[index][buy][transaction]=  max( prices[index]+maximumProfit(index+1,1,transaction-1,n,prices,dp),
        maximumProfit(index+1,0,transaction,n,prices,dp));

    }
}

// index = 0 to n (n+1): i: n to 0
// buy= 0 to 1 (2): j: 0 to 1
// transaction: 2 1 0 , (3): k: 0 to 2
// j==1 , dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
// j==0, dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
// (n+1)*2*3 = n

// Initilization:
// k ==0, sabko zero bana do udhr
// i == n, sabko zero bana do udhr 

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));


    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
            for(int k=1;k<=2;k++){
                if(j==1){
                    dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                }
                else{
                    dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
        }
    }


    return dp[0][1][2];
}