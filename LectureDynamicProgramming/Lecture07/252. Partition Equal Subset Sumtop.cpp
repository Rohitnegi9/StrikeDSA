class Solution {
public:
    bool findSubset(int n, int target, vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)
    return 1;

    if(n==0 || target<0)
    return 0;
    
    if(dp[n][target]!=-1)
    return dp[n][target];

    return  dp[n][target] = findSubset(n-1,target,arr,dp)+findSubset(n-1,target-arr[n-1],arr,dp);
}


bool canPartition(vector<int>& arr) {
    int target = 0, n = arr.size();

    for(int i=0;i<n;i++){
        target+=arr[i];
    }


    if(target%2)
    return 0;
    
    vector<vector<int>>dp(n+1,vector<int>(target/2+1,-1));

    return findSubset(n,target/2,arr,dp);
}
};