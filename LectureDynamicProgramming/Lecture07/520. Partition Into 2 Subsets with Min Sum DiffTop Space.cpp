class Solution {
public:
   
   int findMinDiff(int n, int sum1, int totalSum, vector<int>&arr,vector<vector<int>>&dp){
        
        if(n==0){
            int sum2 = totalSum-sum1;
            return abs(sum1-sum2);
        }

        if(dp[n][sum1]!=-1)
        return dp[n][sum1];

       return dp[n][sum1] = min(findMinDiff(n-1,sum1+arr[n-1],totalSum,arr,dp), findMinDiff(n-1,sum1,totalSum,arr,dp));
   }


    int minDifference(vector<int>& arr) {
        // Your code here
        int sum1 = 0, sum2 = 0, n = arr.size();
        int totalSum = 0;

        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
 
        //3D DP
        // dp[n+1][size][size]
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(target+1,vector<int>(target+1,-1)));
        vector<vector<int>>dp(n+1,vector<int>(totalSum+1,-1));

        return findMinDiff(n,sum1,totalSum,arr,dp);
    }
};