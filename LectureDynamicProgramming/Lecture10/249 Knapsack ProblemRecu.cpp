class Solution {
  public:
    
    int findMaxVal(int n, int W, vector<int>&val, vector<int>&wt){
        
        if(W<0){
            return INT_MIN;
        }

        if(n==0 || W==0)
        return 0;



        return max(findMaxVal(n-1,W,val,wt), val[n-1]+findMaxVal(n-1,W-wt[n-1],val,wt));
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        // Code Here
        int n = wt.size();

        return findMaxVal(n,W,val,wt);
    }
};