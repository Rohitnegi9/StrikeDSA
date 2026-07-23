int LPS(int start, int end, string &s){
   
   if(start==end)
   return 1;

   if(start>end)
   return 0;



    if(s[start]==s[end])
    return 2+LPS(start+1,end-1,s);
    else{
        return max(LPS(start+1,end,s), LPS(start,end-1,s));
    }
}



int longestPalindromeSubseq(string s) {
     
     int n = s.size();

    return LPS(0,n-1,s);
}