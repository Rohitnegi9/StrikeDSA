int climb(int n, vector<int>&dp){
    // base case
    if(n<=2){
        return n;
    }


    // base case handle karo
    if(dp[n]!=-1){
        return dp[n];
    }


    return dp[n] = climb(n-1,dp)+climb(n-2,dp);
}

// dp[n] = climb(n)
// dp[i] = dp[i-1]+dp[i-2]


int climbStairs(int n) {
    // Your code here
    // top down convert
    
    if(n<=2)
    return n;

    vector<int>dp(n+1,-1);

    //  return climb(n,dp);
    // Bottom up: Tabulation method: for loop solve karta hu
    // apne dp ko initlize kar do: loot at the base case of top down approach
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;


    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }


    return dp[n];

    
}