int maximumProfit(int transaction, int n, vector<int>&prices){
   
   if(transaction==0)
   return 0;

   if(n<=1)
   return 0;




    // Current day pe sell nahi karunga
    int targetProfit = maximumProfit(transaction,n-1, prices);
    // current day pe hu sell karunga
    for(int j=n-1;j>=1;j--){
        targetProfit = max(targetProfit, prices[n-1]-prices[j-1]+maximumProfit(transaction-1,j,prices));
    }


    return targetProfit;
}


int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    // n = number of days

    return maximumProfit(2,n,prices);
}