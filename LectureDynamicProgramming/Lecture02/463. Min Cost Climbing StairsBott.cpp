class Solution {
public:
    int minCost(vector<int>& cost, int n,vector<int>&dp){
        if(n<=1)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];

        // how to reach nth stair at minCost
        return dp[n] = min(minCost(cost,n-1,dp)+cost[n-1] , minCost(cost,n-2,dp)+cost[n-2]);
    }

    // dp[n] = minCost(n)
    // dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])

    int minCostClimbingStairs(vector<int>& cost) {
        // code here
        int n = cost.size();
        // vector<int>dp(n+1,-1);
        // return minCost(cost,n,dp);

        // Bottom up:
        vector<int>dp(n+1,-1);

        dp[0] = 0;
        dp[1] = 0;

        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }

        return dp[n];
    }
};