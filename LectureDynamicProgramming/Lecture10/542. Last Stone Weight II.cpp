class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // Your code here

        int totalSum = 0, n = stones.size();
        
        if(n==1)
        return stones[0];

        for(int i=0;i<n;i++){
            totalSum+=stones[i];
        }

        vector<bool>dp(totalSum/2+1,0);
        dp[0] = 1;

        for(int i=0;i<n;i++){
            for(int j = totalSum/2;j>=stones[i];j--){
                dp[j] = dp[j] || dp[j-stones[i]];
            }
        }

        for(int i=totalSum/2;i>0;i--){
            if(dp[i]){
                return totalSum-2*i;
            }
        }

        return 0;
    }
};