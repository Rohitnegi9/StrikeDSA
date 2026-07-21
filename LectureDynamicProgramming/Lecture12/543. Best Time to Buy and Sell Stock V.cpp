class Solution {
public:
     long long maximumProfit(int index, int buy, int transaction, int n, vector<int>&prices,vector<vector<vector<long long>>>&dp){
      
      if(transaction == 0)
      return 0;

      if(index==n){
        return buy == 1? INT_MIN: 0;
      }

      if(dp[index][buy][transaction]!=-1)
      return dp[index][buy][transaction];

       
       if(buy==2){
          // ya toh mein nahi purchase karunga, ya mein buy karunga, pa mein short sellin wala buy karunga

        return dp[index][buy][transaction] = max(maximumProfit(index+1,2,transaction,n,prices,dp), max( -prices[index]+maximumProfit(index+1,0,transaction, n, prices,dp), prices[index]+ maximumProfit(index+1,1,transaction,n, prices,dp)));

       }


       else if(buy==1){
        // short selling : short sell karoge ya nahi karoge
         
         return dp[index][buy][transaction] = max(-prices[index]+maximumProfit(index+1,2,transaction-1,n,prices,dp), maximumProfit(index+1,1,transaction,n,prices,dp));
       }


       else{
        // normal selling: sell kar do aaj, ya na karo

        return dp[index][buy][transaction]= max(prices[index]+maximumProfit(index+1,2,transaction-1,n,prices,dp), maximumProfit(index+1,0,transaction,n,prices,dp));

       }

     }

    long long maxProfit(int k , vector<int>& prices) {
        // Your code here
  
        int n = prices.size();
        vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(3,vector<long long>(k+1,-1)));

        return maximumProfit(0,2,k,n,prices,dp);
    }
};