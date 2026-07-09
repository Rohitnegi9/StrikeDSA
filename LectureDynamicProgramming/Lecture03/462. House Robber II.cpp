class Solution {
public:
    int rob(vector<int>& nums) {
        // code here
        int n = nums.size();

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0],nums[1]);
        }


        // 0 to n-2(Ignore last index)
        // 1 to n-1 (Ignore first index);


        vector<int>dp(3,0);

        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i]+dp[0],dp[1]);
        }

        int result = dp[2];

        // we got answer for the first case: 0 to n-2

        
        // 1 to n-1
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        
        for(int i=3;i<n;i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i]+dp[0],dp[1]);
        }

        result = max(result,dp[2]);

        return result;

        
    }
};