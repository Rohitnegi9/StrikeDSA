class Solution {
public:
    
    bool isMatch(int startIndex1, int endIndex1, int startIndex2, int endIndex2, string &s1, string &s2, vector<vector<vector<vector<int>>>>&dp ){

        if(startIndex1 == endIndex1)
        return s1[startIndex1] == s2[startIndex2];
        

        if(dp[startIndex1][endIndex1][startIndex2][endIndex2]!=-1)
        return dp[startIndex1][endIndex1][startIndex2][endIndex2];

        // check the frequency
        vector<int>freq(26,0);

        for(int i=startIndex1;i<=endIndex1;i++){
            freq[s1[i]-'a']++;
        }

        for(int i=startIndex2;i<=endIndex2;i++){
            freq[s2[i]-'a']--;
        }

        for(auto count: freq){
            if(count)
            return 0;
        }
        
        int size = endIndex1-startIndex1+1;

        for(int len=0;len<size-1;len++){

            bool noSwap = isMatch(startIndex1, startIndex1+len, startIndex2, startIndex2+len, s1,s2,dp) && isMatch(
                startIndex1+len+1,endIndex1,  startIndex2+len+1, endIndex2, s1,s2,dp);

            dp[startIndex1][endIndex1][startIndex2][endIndex2]  = noSwap;

            if(noSwap)
            return true;

            bool swap = isMatch(startIndex1, startIndex1+len, endIndex2-len,endIndex2,s1,s2,dp) && isMatch(
                startIndex1+len+1,endIndex1, startIndex2, endIndex2-len-1,s1,s2,dp);
            
            dp[startIndex1][endIndex1][startIndex2][endIndex2]  = swap;

            if(swap)
            return true;
        }


        return dp[startIndex1][endIndex1][startIndex2][endIndex2] = false;

    }


    bool isScramble(string s1, string s2) {
        // Your code here

        int m = s1.size(), n = s2.size();
        vector<vector<vector<vector<int>>>>dp(31,vector<vector<vector<int>>>(31,vector<vector<int>>(31,vector<int>(31,-1))));

        return isMatch(0,m-1,0,n-1,s1,s2,dp); 
    }
};