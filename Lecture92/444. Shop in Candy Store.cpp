class Solution {
public:
    vector<int> candyStore(vector<int>& prices, int k) {
        // code here
        vector<int>count(2,0);
        
        sort(prices.begin(),prices.end());
        int n = prices.size();

        int i = 0, j= n-1;

        while(i<=j){
            count[0]+= prices[i];
            i++;
            j-=k;
        }

        i = n-1, j =0;

        while(i>=j){
            count[1]+=prices[i];
            i--;
            j+=k;
        }

        return count;
    }
};