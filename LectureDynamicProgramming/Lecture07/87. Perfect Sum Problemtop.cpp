class Solution {
public:
    
    int findSubset(int index, int target, vector<int>& arr,vector<vector<int>>&dp){
        
        if(index<0){
           return target==0;
        }

        if(target<0)
        return 0;

        if(dp[index][target]!=-1)
        return dp[index][target];

        return dp[index][target] = findSubset(index-1,target,arr,dp)+findSubset(index-1,target-arr[index],arr,dp);
    }
  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return findSubset(n-1,target,arr,dp);
    }
};