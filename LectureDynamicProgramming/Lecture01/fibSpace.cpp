int fib(int n) {
    


    // space optimization

    if(n<=1)
    return n;

    if(n==2)
    return 1;

    vector<int>dp(3);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[0]+dp[1];
    }


    return dp[2];
}