class Solution {
public:
    int LongestBitonicSequence(int n, vector<int>& nums) {
        // Your code here

        vector<int>LIS(n,1);
        vector<int>LDS(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                }
            }
        }


        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    LDS[i] = max(LDS[i],1+LDS[j]);
                }
            }
        }


        int result = 0;

        for(int i=0;i<n;i++){
            if(LIS[i]!=1 && LDS[i]!=1){
                result = max(result, LIS[i]+LDS[i]-1);
            }
        }

        return result;
    }
};