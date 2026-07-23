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

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return LCS(m,n,text1,text2,dp);
}