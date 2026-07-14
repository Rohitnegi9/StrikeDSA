class Solution {
public:
    
    int findSubset(int n, int target, vector<int>& arr,vector<vector<int>>&dp){
        
        if(n==0){
           return target==0;
        }

        if(target<0)
        return 0;

        if(dp[n][target]!=-1)
        return dp[n][target];

        return dp[n][target] = findSubset(n-1,target,arr,dp)+findSubset(n-1,target-arr[n-1],arr,dp);
    }
  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        // n: total element in array
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return findSubset(n,target,arr,dp);
    }
};