class Solution {
public:
    int countPS(string s) {
        // Your code here
        
        int n = s.size();

        vector<vector<bool>>dp(n,vector<bool>(n,0));

        // 1 size ki string: unki: Diagnol ko 1 kar do

        for(int i=0;i<n;i++)
        dp[i][i] = 1;

        int totalPallindrome = 0;

        // 2 3 4 ..,. n

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;

                if(s[i]==s[j]&&(len==2 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                    totalPallindrome++;
                }
            }
        }

        return totalPallindrome;

    }
};