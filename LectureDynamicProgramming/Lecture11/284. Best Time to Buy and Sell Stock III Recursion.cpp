int maximumProfit(int index, int buy, int transaction, int n, vector<int>&prices){

    if(transaction==0 || index==n){
        return 0;
    };



    //
    if(buy){
        
        // Either I can buy the stock or I will not buy the stock

    return  max( -prices[index]+maximumProfit(index+1,0,transaction,n,prices),
        maximumProfit(index+1,1,transaction,n,prices));

    }
    else{
         
         // Eithr I can sell the stock today or I will sell the stock today

         return  max( prices[index]+maximumProfit(index+1,1,transaction-1,n,prices),
        maximumProfit(index+1,0,transaction,n,prices));

    }
}



int maxProfit(vector<int>& prices) {

    int n = prices.size();

    return maximumProfit(0,1,2,n,prices);
}