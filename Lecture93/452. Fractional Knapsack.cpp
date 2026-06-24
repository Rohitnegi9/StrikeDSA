bool comp(pair<int,int>&a, pair<int,int>&b){
     
    return a.first*b.second >= b.first*a.second;
}

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>arr;
        int n = val.size();

        for(int i=0;i<n;i++){
            arr.push_back({val[i],wt[i]});
        }

        // val/wt
        sort(arr.begin(),arr.end(),comp);
        
        int i = 0;
        double totalProfit = 0.0;

        while(i<n&&capacity){
            
            // available weight item <= capacity , we can directly select the whole profit, select the whole Iteam
            if(arr[i].second<=capacity){
                totalProfit+= arr[i].first;
                capacity-=arr[i].second;
            }
            else{
                double a = arr[i].first;
                a/=arr[i].second;

                totalProfit+= a*capacity;
                capacity = 0;
            }
            i++;

            // capacity ke hishab select karn padega, take the fraction of item
            
        }


        return totalProfit;

    }
};