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


int climbStairs(int n) {
    // Your code here
    // top down convert
    vector<int>dp(n+1,-1);

    return climb(n,dp);
}