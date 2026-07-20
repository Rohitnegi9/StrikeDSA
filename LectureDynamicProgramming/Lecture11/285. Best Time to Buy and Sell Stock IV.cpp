int maxProfit(int transaction, vector<int>& prices) {
     
        int n = prices.size();
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    vector<vector<int>>prev(2,vector<int>(transaction+1,0));


    for(int i=n-1;i>=0;i--){
        vector<vector<int>>curr(2,vector<int>(transaction+1,0));
        for(int j=0;j<=1;j++){
            for(int k=1;k<=transaction;k++){
                if(j==1){
                    curr[j][k] = max(-prices[i]+prev[0][k],prev[1][k]);
                }
                else{
                    curr[j][k] = max(prices[i]+prev[1][k-1],prev[0][k]);
                }
            }
        }

        prev = curr;
    }

    // Time Complexity: n*Transaction
    // Space Complexity: transaction*2



    return prev[1][transaction];
}