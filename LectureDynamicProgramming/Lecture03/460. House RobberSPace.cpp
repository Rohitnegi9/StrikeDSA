class Solution {
public:
    

    int rob(vector<int>& nums) {
        // code here
        int n = nums.size();
        // size of array
        if(n==1){
         return nums[0];
        }


        if(n==2){
            return max(nums[0],nums[1]);
        }

        vector<int>dp(3,0);


        // Bottom up
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);

        // for(int i=2;i<n;i++){
        //     dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        // }

        for(int i=2;i<n;i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i]+dp[0],dp[1]);
        }

        return dp[2];
    }
};