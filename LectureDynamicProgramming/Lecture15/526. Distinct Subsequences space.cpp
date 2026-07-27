class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        // vector<vector< unsigned long long>>dp(m+1,vector< unsigned long long>(n+1,0));

        // if column is zero, put 1
        // for(int i=0;i<=m;i++)
        // dp[i][0] = 1;

        vector<unsigned long long>prev(n+1,0);

        prev[0] = 1;



        for(int i=1;i<=m;i++){
            vector<unsigned long long>curr(n+1,0);
            curr[0] = 1;
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                curr[j] = prev[j-1]+prev[j];
                else
                curr[j] = prev[j];
            }

            prev = curr;
        }

        return prev[n];
    }
};