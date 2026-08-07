class Solution {
public:

    int findMaximumCherry(int r1, int c1, int r2, int c2, int row, int col ,vector<vector<int>>& grid){

        if(c1<0 || c2< 0 || c1>=col || c2>=col)
        return INT_MIN;


        if(r1==row-1){
            if(c1!=c2){
                return grid[r1][c1]+grid[r2][c2];
            }
            else{
                return grid[r1][c1];
            }
        }

        int cherries = grid[r1][c1];

        if(c1!=c2)
        cherries+= grid[r2][c2];


        // total 9 cases: 

        // LL LR LS SL SS SR RL RS RR
        
        int LL = findMaximumCherry(r1+1,c1-1,r2+1,c2-1,row,col,grid);
        int LR = findMaximumCherry(r1+1,c1-1,r2+1,c2+1,row,col,grid);
        int LS = findMaximumCherry(r1+1,c1-1,r2+1,c2,row,col,grid);
        int SL = findMaximumCherry(r1+1,c1,r2+1,c2-1,row,col,grid);
        int SS = findMaximumCherry(r1+1,c1,r2+1,c2,row,col,grid);
        int SR = findMaximumCherry(r1+1,c1,r2+1,c2+1,row,col,grid);
        int RL = findMaximumCherry(r1+1,c1+1,r2+1,c2-1,row,col,grid);
        int RS = findMaximumCherry(r1+1,c1+1,r2+1,c2,row,col,grid);
        int RR = findMaximumCherry(r1+1,c1+1,r2+1,c2+1,row,col,grid);
        

        int next = max({LL,LR,LS,SL,SS,SR,RL,RS,RR});

        if(next==INT_MIN)
        return INT_MIN;

        return cherries+next;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        // Your code here
        int m = grid.size();
        int n = grid[0].size();

        return max(0, findMaximumCherry(0,0,0,n-1,m,n,grid));
    }
};