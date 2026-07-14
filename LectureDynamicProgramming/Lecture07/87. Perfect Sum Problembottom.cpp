class Solution {
public:  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        if(n==0)
        return target==0;
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        dp[0][0] = 1;
         
        if(arr[0]<=target)
        dp[0][arr[0]]++;


        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){

                if(j-arr[i]>=0)
                dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i]];
                else
                dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n-1][target];
    }
};