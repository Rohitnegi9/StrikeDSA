    class Solution {
public:

    // [0,1,2,4,5,6,9]
    //.0  1 2 3 4 5 6

    // start = 0, end = 4 , rodStart = 0, rodEnd = 9
    // k = 2 , cuts[k] = 4

    // leftside = 0,4 (0,1)             // rightSide = 4,9 (3,4)
    
    int findMinCost(int start, int end, vector<int>&cuts,vector<vector<int>>&dp){
        
        if(start+1 == end){
            return 0;
        }

        if(dp[start][end]!=-1)
        return dp[start][end];

        // try all the cuts
        int result = INT_MAX;
        for(int k=start+1;k<end;k++){
           // leftSide, rightSide
           int answer = cuts[end]-cuts[start]+ findMinCost(start,k,cuts,dp)+findMinCost(k,end,cuts,dp);
           result = min(answer,result);
        }

        return dp[start][end]= result;
    }
    
    // start = 0 ---> cuts.size()-2
    // end == cuts.size()-1 to 1

    int minCost(int n, vector<int>& cuts) {
        // Your code here
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));

        return findMinCost(0,cuts.size()-1,cuts,dp);
    }
};