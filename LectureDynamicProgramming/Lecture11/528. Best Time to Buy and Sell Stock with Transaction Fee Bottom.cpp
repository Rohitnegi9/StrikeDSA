class Solution {
public:
    
    int maximumProfit(int index, int buy, int n, int fee, vector<int>& prices,vector<vector<int>>&dp){

        if(index==n)
        return 0;


        if(dp[index][buy]!=-1)
        return dp[index][buy];


        if(buy){
            return dp[index][buy]= max(-prices[index]+maximumProfit(index+1,0,n,fee,prices,dp), maximumProfit(index+1,1,n,fee,prices,dp));
        }
        else{
            return dp[index][buy] = max(prices[index]-fee+maximumProfit(index+1,1,n,fee,prices,dp), maximumProfit(index+1,0,n,fee,prices,dp));
        }
    }

    // index: 0 to n: n+1: i: n to 0
    // buy: 1 to 0: 2: j: 0 to 1
    // dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
    // dp[i][j] = max(prices[i]-fee+dp[i+1][1], dp[i+1][0]);

    int maxProfit(vector<int>& prices, int fee) {
        // Your code here
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));


        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
                else
                dp[i][j] = max(prices[i]-fee+dp[i+1][1], dp[i+1][0]);
            }
        }

        return dp[0][1];
    }
};