int LCS(int m, int n, string &text1, string &text2,vector<vector<int>>&dp){

     if(m==0 || n==0)
     return 0;

     if(dp[m][n]!=-1)
     return dp[m][n];


    // char will match or they will not match
    if(text1[m-1]==text2[n-1]){
        return dp[m][n] = 1+ LCS(m-1,n-1,text1,text2,dp);
    }
    else{
        return dp[m][n] = max(LCS(m,n-1,text1,text2,dp), LCS(m-1,n,text1,text2,dp));
    }
}

// m = i, n = j
// dp[i][j] = 1+dp[i-1][j-1];, match hoga
// dp[i][j]= max(dp[i][j-1],dp[i-1][j])
// i: m to 0
//j: n to 0

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    //  vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    vector<int>prev(n+1,0);

    for(int i=1;i<=m;i++){
        vector<int>curr(n+1,0);
        for(int j=1;j<=n;j++){
            if(text1[i-1]==text2[j-1])
            curr[j] = 1+prev[j-1];
            else
            curr[j]= max(curr[j-1],prev[j]);
        }
        prev = curr;
    }
    
    return prev[n];
    
}