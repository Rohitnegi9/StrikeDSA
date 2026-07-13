// Homework
class Solution {
public:
    int rob(vector<int>& nums) {
        // Your code here
        // Space optimization starting from begining
        int n=nums.size()-1;
        if(n==0) return nums[0];
        if(n==1) return max(nums[0],nums[1]);
        int dp1=nums[0],dp2=max(nums[0],nums[1]),dp3;
        for(int i=2;i<=n;i++){
            dp3=max(nums[i]+dp1,dp2);
            dp1=dp2;
            dp2=dp3;
        }
        return dp3;
    }
};
