int countHops(int n) {
    // Your code here

    if(n<=2)
    return n;

    if(n==3)
    return 4;  

    vector<int>dp(4);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4;i<=n;i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
        dp[3] = dp[0]+dp[1]+dp[2];
    }


    return dp[3];
     
}