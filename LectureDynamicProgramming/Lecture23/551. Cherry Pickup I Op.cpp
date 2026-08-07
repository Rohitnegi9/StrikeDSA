class Solution {
public:


    int findMaximumCherryPick(int r1, int c1, int r2, int n , vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        
        int c2 = (r1+c1)-r2;

        // base case
        if(r1>=n || r2>=n || c1>=n || c2>=n)
        return INT_MIN;

        if(grid[r1][c1]== -1 || grid[r2][c2]==-1)
        return INT_MIN;


        // I have reached my tatget
        if(r1==n-1 && c1==n-1)
        return grid[n-1][n-1];

        if(dp[r1][c1][r2]!=-1)
        return dp[r1][c1][r2];



        int cherries = grid[r1][c1];

        if(r1!=r2 || c1!=c2)
        cherries+= grid[r2][c2];





        // DD, DR, RD, RR

        int DD = findMaximumCherryPick(r1+1,c1,r2+1,n,grid,dp);
        int DR = findMaximumCherryPick(r1+1,c1,r2,n,grid,dp);
        int RD = findMaximumCherryPick(r1,c1+1,r2+1,n,grid,dp);
        int RR = findMaximumCherryPick(r1,c1+1,r2,n,grid,dp);

        int pick = max({DD,DR,RD,RR});

        if(pick==INT_MIN)
        return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries+pick;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // Your code here
        int n = grid.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n,vector<int>(n,-1)));
        int answer = findMaximumCherryPick(0,0,0,n,grid,dp);


        return max(0,answer);
    }
};