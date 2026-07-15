class Solution {
public:

    int totalWays(int n, int amount, vector<int>& coins){
         
         if(amount==0)
         return 1;

         if(n==0 || amount<0)
         return 0;




        return totalWays(n-1,amount,coins)+totalWays(n,amount-coins[n-1],coins);
    }

    int change(int amount, vector<int>& coins) {
        // Your code here

        int n = coins.size();

        return totalWays(n,amount,coins);
    }
};