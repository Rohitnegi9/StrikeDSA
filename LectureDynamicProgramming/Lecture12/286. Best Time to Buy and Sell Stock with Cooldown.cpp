int maxProfit(vector<int>& prices) {
    int maximumProfit = -prices[0], n= prices.size();

    vector<int>dp(n+1,0);

    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1], prices[i-1]+maximumProfit);
        maximumProfit = max(maximumProfit, dp[i-2]-prices[i-1]);
    }

    return dp[n];
}