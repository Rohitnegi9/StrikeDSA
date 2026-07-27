int minStep(int m, int n, string &word1, string &word2,vector<vector<int>>&dp){
    
    if(m==0)
    return n;

    if(n==0)
    return m;

    if(dp[m][n]!=-1)
    return dp[m][n];



    if(word1[m-1]==word2[n-1]){
        return dp[m][n] = minStep(m-1,n-1,word1,word2,dp);
    }
    else{
        int deleted = minStep(m-1,n,word1,word2,dp);
        int inserted = minStep(m,n-1,word1,word2,dp);
        int replaced = minStep(m-1,n-1,word1,word2,dp);

        return dp[m][n] = 1+ min(deleted,min(inserted,replaced));
    }
}

// bottom up
// m = m to 0: i
// n = n to 0: j

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    
    // column zero ko fill kar do
    for(int i=0;i<=m;i++)
    dp[i][0] = i;

    // row zero ko fill kar do: column ki value hoga
    for(int j=0;j<=n;j++)
    dp[0][j] = j;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }

    return dp[m][n];
}