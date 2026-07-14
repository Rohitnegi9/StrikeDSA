class Solution {
public:
   
   int findMinDiff(int n, int sum1, int sum2, vector<int>&arr,vector<vector<vector<int>>>&dp){
        
        if(n==0){
            return abs(sum1-sum2);
        }

        if(dp[n][sum1][sum2]!=-1)
        return dp[n][sum1][sum2];

       return dp[n][sum1][sum2] = min(findMinDiff(n-1,sum1+arr[n-1],sum2,arr,dp), findMinDiff(n-1,sum1,sum2+arr[n-1],arr,dp));
   }


    int minDifference(vector<int>& arr) {
        // Your code here
        int sum1 = 0, sum2 = 0, n = arr.size();
        int target = 0;

        for(int i=0;i<n;i++){
            target+=arr[i];
        }
 
        //3D DP
        // dp[n+1][size][size]
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(target+1,vector<int>(target+1,-1)));

        return findMinDiff(n,sum1,sum2,arr,dp);
    }
};