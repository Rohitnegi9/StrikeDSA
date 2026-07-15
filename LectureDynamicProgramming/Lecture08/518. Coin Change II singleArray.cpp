class Solution {
public:

    int change(int amount, vector<int>& coins) {
        // Your code here

        int n = coins.size();

        // first column ko fill kar do 1 se
        vector<int>curr(amount+1,0);

        curr[0] = 1;

        // 0th row, oth column fill kar liya hai, initlize kar liya

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                curr[j] = curr[j]+curr[j-coins[i-1]];
            }
        }


        return curr[amount];
    }
};