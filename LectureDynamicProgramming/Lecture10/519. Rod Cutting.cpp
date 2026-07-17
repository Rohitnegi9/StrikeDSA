class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        // Your code here
        if(n==0)
        return 0;

        if(n==1)
        return price[0];

        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        dp[i] = price[i-1];

     // rod length : 4
     // 

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i], dp[j]+ dp[i-j]);
            }
        }

        return dp[n];
    }
};