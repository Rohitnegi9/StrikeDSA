class Solution {
public:
    
    int maxProfit(int n, vector<int>& price){
       
       if(n==0)
       return 0;


       int result = 0;
       for(int j=1;j<=n;j++){
         result = max(result, price[j-1]+maxProfit(n-j,price));
       }


       return result;

    }

    int cutRod(vector<int>& price, int n) {
        // Your code here

        return maxProfit(n,price);


    }
};