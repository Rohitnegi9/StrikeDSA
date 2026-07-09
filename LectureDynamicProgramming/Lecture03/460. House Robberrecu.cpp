class Solution {
public:
    
    int maxAmountRob(int n, vector<int>& nums){
        
        // base case
        if(n==0){
            return nums[0];
        }

        if(n==1){
            return max(nums[0],nums[1]);
        }

        

        
        return max(nums[n]+maxAmountRob(n-2,nums),maxAmountRob(n-1,nums));

    }

    int rob(vector<int>& nums) {
        // code here
        int n = nums.size();
        return maxAmountRob(n-1,nums);
    }
};