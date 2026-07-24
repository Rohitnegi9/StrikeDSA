int LCSubStr(int m, int n, int &result, string &s1, string &s2, vector<vector<int>>&dp){
    
    if(m==0 || n==0)
    return 0;
    
    if(dp[m][n]!=-1)
    return dp[m][n];

    // if text matches
    int answer = 0;
    if(s1[m-1]==s2[n-1]){
        answer = 1+LCSubStr(m-1,n-1,result,s1,s2,dp);
        result = max(answer,result);
    }


    LCSubStr(m-1,n,result,s1,s2,dp);
    LCSubStr(m,n-1,result,s1,s2,dp);


    return dp[m][n] = answer;
    // if it doesn't match
}

// m = m to 0: i
// n = n to 0: j



int longestCommonSubstr(string s1, string s2) {
   int m = s1.size() , n = s2.size(), result = 0;

   vector<vector<int>>dp(m+1,vector<int>(n+1,0));

   
   for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        int answer = 0;
        if(s1[i-1]==s2[j-1]){
            answer = 1+dp[i-1][j-1];
            result = max(answer,result);
        }
        dp[i][j] = answer;
    }
   }


   return result;
}