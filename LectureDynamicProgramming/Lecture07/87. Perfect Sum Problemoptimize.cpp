class Solution {
public:  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        if(n==0)
        return target==0;
        
        // vector<vector<int>>dp(n,vector<int>(target+1,0));
        vector<int>prev(target+1,0);
        
        prev[0] = 1;
         
        if(arr[0]<=target)
        prev[arr[0]]++;


        for(int i=1;i<n;i++){
            vector<int>curr(target+1,0);
            for(int j=0;j<=target;j++){

                if(j-arr[i]>=0)
                curr[j] = prev[j]+prev[j-arr[i]];
                else
                curr[j] = prev[j];
            }

            prev = curr;
        }

        return prev[target];
    }
};