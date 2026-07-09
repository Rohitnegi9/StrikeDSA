
int fib(int n) {
    // Your code here
    

    if(n<=1)
    return n;

    vector<int>dp(n+1);
    // n = 0, dp = [0]
    // base case fill karo Dp ke anadar
    dp[0] = 0;
    dp[1] = 1;

    //  dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);
    //  dp[i] = dp[i-1]+dp[i-2];

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}