class Solution {
public:
    int minCost(vector<int>& cost, int n){
        if(n<=1)
        return 0;


        // how to reach nth stair at minCost
        return min(minCost(cost,n-1)+cost[n-1] , minCost(cost,n-2)+cost[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // code here
        int n = cost.size();

        return minCost(cost,n);
    }
};