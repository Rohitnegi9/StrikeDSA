class Solution {
public:
    int minCut(string s) {
        // Your code here

         int n = s.size();

         if(n==1)
         return 0;

        vector<vector<bool>>pallindrome(n,vector<bool>(n,0));

        // 1 size ki string: unki: Diagnol ko 1 kar do

        for(int i=0;i<n;i++)
        pallindrome[i][i] = 1;


        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;

                if(s[i]==s[j]&&(len==2 || pallindrome[i+1][j-1])){
                    pallindrome[i][j] = 1;
                }
            }
        }


        vector<int>dp(n,INT_MAX);

        dp[n-1] = 0;


        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                if(pallindrome[i][j]){
                    if(j==n-1)
                    dp[i] = 0;
                    else
                    dp[i] = min(dp[i], 1+dp[j+1]);
                }
            }
        }


        return dp[0];



    }
};