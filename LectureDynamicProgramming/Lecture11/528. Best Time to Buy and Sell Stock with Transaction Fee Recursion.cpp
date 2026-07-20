class Solution {
public:
    
    int maximumProfit(int index, int buy, int n, int fee, vector<int>& prices){

        if(index==n)
        return 0;


        if(buy){
            return max(-prices[index]+maximumProfit(index+1,0,n,fee,prices), maximumProfit(index+1,1,n,fee,prices));
        }
        else{
            return max(prices[index]-fee+maximumProfit(index+1,1,n,fee,prices), maximumProfit(index+1,0,n,fee,prices));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        // Your code here
        int n = prices.size();
        return maximumProfit(0,1,n,fee,prices);
    }
};