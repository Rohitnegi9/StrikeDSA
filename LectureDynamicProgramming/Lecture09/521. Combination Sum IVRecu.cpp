class Solution {
public:
    // [1,2,3,4,5]
    int findTotalCombination(int n, int target, vector<int>&nums){
        if(target==0)
        return 1;

        if(target<0)
        return 0;
         
       int result = 0;
       for(int j=0;j<n;j++){
          result+= findTotalCombination(n,target-nums[j],nums);
       }


       return result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // Your code here

        int n = nums.size();
        return findTotalCombination(n,target,nums);
    }
};