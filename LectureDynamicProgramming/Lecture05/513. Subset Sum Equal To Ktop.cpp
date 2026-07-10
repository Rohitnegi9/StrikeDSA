class Solution {
public:
    
    bool findSubset(int index, int sum, vector<int>& arr,vector<vector<int>>&dp){
        
        if(sum==0)
        return 1;

        if(sum<0 || index<0)
        return 0;


        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }

        // not pick or pick
       return dp[index][sum] = findSubset(index-1,sum,arr,dp) || findSubset(index-1,sum-arr[index],arr,dp);
    }


    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Your code here
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // dp[n][k+1]
        return findSubset(n-1,k,arr,dp);
    }
};