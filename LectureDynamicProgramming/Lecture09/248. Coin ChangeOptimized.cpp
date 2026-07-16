class Solution {
public:


    int coinChange(vector<int>& coins, int amount) {
        // Your code here
         int n = coins.size();
        //  vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
         // zero row ko initlize kar do , 1e9
         // zero column ko initlize kar do zero se
          
        vector<int>prev(amount+1,-1);
      

         for(int j=0;j<=amount;j++)
         prev[j] = 1e9;



        
        prev[0] = 0;
         


         for(int i=1;i<=n;i++){
            vector<int>curr(amount+1);
            curr[0] = 0;
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                curr[j] = min(prev[j],1+curr[j-coins[i-1]]);
                else
                curr[j] = prev[j];
            }

            prev = curr;
         }


         // dp[n][amount]

         return prev[amount]>=1e9 ? -1: prev[amount];


        
    }
};