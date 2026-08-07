class Solution {
public:
     
     int IncreasingPath(int r1, int c1, int rows, int cols, vector<vector<int>>& grid,vector<vector<int>>&dp){

        if(dp[r1][c1]!=-1)
        return dp[r1][c1];

        long long result = 1;
        // up, down, left, right
        if(r1-1 >=0 && grid[r1-1][c1]>grid[r1][c1]){
            result+= IncreasingPath(r1-1,c1,rows,cols,grid,dp);
        }
        if(r1+1 <rows && grid[r1+1][c1]>grid[r1][c1]){
            result+= IncreasingPath(r1+1,c1,rows,cols,grid,dp);
        }
        if(c1-1 >=0 && grid[r1][c1-1]>grid[r1][c1]){
            result+= IncreasingPath(r1,c1-1,rows,cols,grid,dp);
        }
        if(c1+1 <cols && grid[r1][c1+1]>grid[r1][c1]){
            result+= IncreasingPath(r1,c1+1,rows,cols,grid,dp);
        }

        return  dp[r1][c1] = result%1000000007;

     }

    int countPaths(vector<vector<int>>& grid) {
        // Your code here

        int rows = grid.size(), cols = grid[0].size();
        long long totalPaths = 0;

        vector<vector<int>>dp(rows, vector<int>(cols,-1));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                totalPaths+= IncreasingPath(i,j,rows,cols,grid,dp);
                totalPaths%=1000000007;
            }
        }

        return totalPaths;
    }
};