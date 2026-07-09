class Solution {
public:
    

    int minimizeEnergy(vector<int>& heights, int k) {
        // Your code here

        int n = heights.size();
        if(n==1)
        return 0;

        vector<int>dp(n,-1);

        dp[0] = 0;

        for(int index=1;index<n;index++){
            int result = INT_MAX;
            
            for(int i=1; i<=k && i<=index; i++){
                result = min(result, abs(heights[index]-heights[index-i])+ dp[index-i]);
            }

            dp[index] = result;

        }

        return dp[n-1];

        
    }
};