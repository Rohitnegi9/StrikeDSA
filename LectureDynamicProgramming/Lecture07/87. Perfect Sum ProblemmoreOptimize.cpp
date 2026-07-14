class Solution {
public:  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        if(n==0)
        return target==0;
        
        // vector<vector<int>>dp(n,vector<int>(target+1,0));
        vector<int>curr(target+1,0);
        
        curr[0] = 1;
       
         
        if(arr[0]<=target)
        curr[arr[0]]++;


        for(int i=1;i<n;i++){
            for(int j=target;j>=0;j--){
                if(j-arr[i]>=0)
                curr[j] = curr[j]+curr[j-arr[i]];
                else
                curr[j] = curr[j];
            }

        }

        return curr[target];
    }
};