class Solution {
public:
    int numSquares(int n) {
        // Your code here
        if(n<=3)
        return n;

        // 0: 0, 1: 1, 2:2., 3:3

        vector<int>MinimumPerfectSquare(n+1,INT_MAX);
        MinimumPerfectSquare[0]=0;
        MinimumPerfectSquare[1]=1;
        MinimumPerfectSquare[2]=2;
        MinimumPerfectSquare[3]=3;
        

        for(int i=4;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                MinimumPerfectSquare[i] = min(MinimumPerfectSquare[i],1+MinimumPerfectSquare[i-j*j]);
            }
        }

        return MinimumPerfectSquare[n];

    }

    // n*sqrt(n)
};