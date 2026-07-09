class Solution {
public:
    


    int minimizeEnergy(vector<int>& heights, int k) {
        // Your code here

        int n = heights.size();
        if(n==1)
        return 0;

     

        k = min(k,n-1);

        vector<int>dp(k+1);

        dp[0] = 0;

        // 1 2 3 k(index): initilize first  k+1 values

        for(int index=1;index<=k;index++){
            int result = INT_MAX;
            
            for(int i=1; i<=k && i<=index; i++){
                result = min(result, abs(heights[index]-heights[index-i])+ dp[index-i]);
            }

            dp[index] = result;

        }


        for(int index=k+1;index<n;index++){
            int result = INT_MAX;

            // saare value ko ek ek place aage shift karo
            for(int i=1;i<=k;i++){
                dp[i-1] = dp[i];
            }


            
            for(int i=1; i<=k && i<=index; i++){
                result = min(result, abs(heights[index]-heights[index-i])+ dp[k-i]);
            }

            dp[k] = result;
        }


        // k+1;

        return dp[k];



       

        
    }
};