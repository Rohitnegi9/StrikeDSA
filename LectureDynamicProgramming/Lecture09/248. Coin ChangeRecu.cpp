class Solution {
public:

    int findMinCoin(int n, int amount, vector<int>&coins){
        
        if(amount==0)
        return 0;

        if(n==0 || amount<0)
        return 1e9;


       return min(findMinCoin(n-1,amount,coins), 1+findMinCoin(n,amount-coins[n-1],coins));
    }

    int coinChange(vector<int>& coins, int amount) {
        // Your code here
         int n = coins.size();
        int answer = findMinCoin(n,amount,coins);

        return answer>=1e9? -1: answer;
    }
};