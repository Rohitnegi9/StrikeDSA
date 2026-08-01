int findTotalFloor(int eggs, int moves,vector<vector<int>>&dp){
    if(eggs==0 || moves==0)
    return 0;

    if(eggs==1)
    return moves;

    if(dp[eggs][moves]!=-1)
    return dp[eggs][moves];


    return dp[eggs][moves] = 1+findTotalFloor(eggs-1,moves-1,dp)+findTotalFloor(eggs,moves-1,dp);
}


int eggDrop(int n, int k) {

    // moves = 0,1,2,3,4,5   : k = 36
    // 8
    
    vector<vector<int>>dp(n+1, vector<int>(k+1,-1));

    int moves = 0;
    while(findTotalFloor(n,moves,dp)<k)
    {
        moves++;
    }

    return moves;
}