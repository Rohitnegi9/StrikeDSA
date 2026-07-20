int maxProfit(vector<int>& prices) {
    int n = prices.size(), prevSmallStockPrice = prices[0], profit = 0;


    for(int i=1;i<n;i++){
        if(prices[i]>prevSmallStockPrice){
            profit = max(profit, prices[i]-prevSmallStockPrice);
        }
        else{
            prevSmallStockPrice = prices[i];
        }
    }


    return profit;
}