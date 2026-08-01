


int eggDrop(int n, int k) {

    // moves = 0,1,2,3,4,5   : k = 36
    // 8
    // eggs: 4, moves= 3
    
    vector<vector<int>>dp(n+1, vector<int>(k+1,0));

    for(int j=0;j<=k;j++)
    dp[1][j] = j;

    // int moves = 0;
    // while(findTotalFloor(n,moves,dp)<k)
    // {
    //     moves++;
    // }

    for(int moves=1;moves<=k;moves++){
        for(int eggs=2;eggs<=n;eggs++){
            dp[eggs][moves] = 1+dp[eggs-1][moves-1]+dp[eggs][moves-1];
        }

        if(dp[n][moves]>=k)
        return moves;
    }
    

    return k;
   
}