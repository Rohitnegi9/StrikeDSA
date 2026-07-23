int LCS(int m, int n, string &text1, string &text2){

     if(m==0 || n==0)
     return 0;


    // char will match or they will not match
    if(text1[m-1]==text2[n-1]){
        return 1+ LCS(m-1,n-1,text1,text2);
    }
    else{
        return max(LCS(m,n-1,text1,text2), LCS(m-1,n,text1,text2));
    }
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();

    return LCS(m,n,text1,text2);
}