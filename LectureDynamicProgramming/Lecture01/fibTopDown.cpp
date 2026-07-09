int fibonacci(int n, vector<int>&dp){
     
    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);

}

int fib(int n) {
    // Your code here
    
    vector<int>dp(n+1,-1);
    return fibonacci(n,dp);
}