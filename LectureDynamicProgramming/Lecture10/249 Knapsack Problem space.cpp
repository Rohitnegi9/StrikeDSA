class Solution {
  public:

    // n = rows, = i
    // W = col = j
    // dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        // Code Here
        int n = wt.size();
         
        // vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        // 0th row and Oth column sabko zero bana diya hai
        vector<int>prev(W+1,0);

        for(int i=1;i<=n;i++)
        {
            vector<int>curr(W+1,0);
            for(int j=1;j<=W;j++){
                if(j-wt[i-1]>=0)
                curr[j] = max(prev[j],val[i-1]+prev[j-wt[i-1]]);
                else
                curr[j] = prev[j];
            }
            prev = curr;
        }


        return prev[W];
    }
};