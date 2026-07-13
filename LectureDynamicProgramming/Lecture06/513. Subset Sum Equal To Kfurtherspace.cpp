class Solution {
public:
    

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        
        
        // j == 0, value kar do

        vector<int>curr(k+1,0);

        curr[0] = 1;
        
        if(arr[0]<=k)
        curr[arr[0]] = 1;

        // first row and first column fill kar diya hai


        for(int i=1;i<n;i++){
            for(int j=k;j>0;j--){
                if(j-arr[i]>=0)
                curr[j] = curr[j]||curr[j-arr[i]];
            }
        }


        return curr[k];        
    }
};