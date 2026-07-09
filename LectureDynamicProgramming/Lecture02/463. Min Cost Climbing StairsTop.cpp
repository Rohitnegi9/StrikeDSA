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

    int minCostClimbingStairs(vector<int>& cost) {
        // code here
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return minCost(cost,n,dp);
    }
};