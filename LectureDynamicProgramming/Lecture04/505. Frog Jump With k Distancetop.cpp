class Solution {
public:
    
    int minEnergy(int index, vector<int>& heights, int k,vector<int>&dp){
        if(index==0)
        return 0;
        
        if(dp[index]!=-1){
            return dp[index];
        }

        int result = INT_MAX; 

        for(int i=1; i<=k && i<=index; i++){
            result = min(result, abs(heights[index]-heights[index-i])+ minEnergy(index-i,heights,k,dp));
        }

        return dp[index] = result;
    }


    int minimizeEnergy(vector<int>& heights, int k) {
        // Your code here

        int n = heights.size();
        vector<int>dp(n,-1);

        return minEnergy(n-1,heights,k,dp);
    }
};