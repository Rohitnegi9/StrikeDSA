class Solution {
public:
    
    int maxAmountRob(int n, vector<int>& nums,vector<int>&dp){
        
        // base case
        if(n==0){
            return nums[0];
        }

        if(n==1){
            return max(nums[0],nums[1]);
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        
        return dp[n] = max(nums[n]+maxAmountRob(n-2,nums,dp),maxAmountRob(n-1,nums,dp));

    }

    int rob(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxAmountRob(n-1,nums,dp);
    }
};