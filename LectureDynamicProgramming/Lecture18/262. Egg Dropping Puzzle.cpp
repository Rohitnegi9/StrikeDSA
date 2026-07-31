int findMinMoves(int eggs, int floors, vector<vector<int>>&dp){
    if(eggs==1)
    return floors;

    if(floors==0)
    return 0;
     
    if(dp[eggs][floors]!=-1)
    return dp[eggs][floors];

    int result = INT_MAX;

    for(int j=1;j<=floors;j++){
        int answer = 1+ max(findMinMoves(eggs-1,j-1,dp),findMinMoves(eggs,floors-j,dp));
        result = min(answer,result);
    }

    return dp[eggs][floors] = result;
}

// n*k*k
// eggs*floor*floor

int eggDrop(int n, int k) {
    
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return findMinMoves(n,k,dp);
}