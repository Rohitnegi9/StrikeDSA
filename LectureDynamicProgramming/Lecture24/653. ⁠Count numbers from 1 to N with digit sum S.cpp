class Solution {
public:
    // n= 4592
    // 0 1 2 3 (0)
    // 4: (1)
    long long findTotalDigit(int index, int s, bool tight,  vector<int>&nums, vector<vector<vector<long long>>>&dp){

        if(s==0)
        return 1;

        if(s<0 || index==nums.size())
        return 0;
        
        if(dp[index][s][tight]!=-1)
        return dp[index][s][tight];

        long long result = 0;

        if(tight){
            for(int i=0;i<nums[index];i++){
                result+=findTotalDigit(index+1,s-i,0,nums,dp);
            }

            result+=findTotalDigit(index+1,s-nums[index],1,nums,dp);
        }
        else{
            for(int i=0;i<=9;i++){
                result+=findTotalDigit(index+1,s-i,0,nums,dp);
            }
        }

        return dp[index][s][tight] = result;
    }

    long long countWithDigitSum(long long n, int s) {
        // Your code here

        if(s==0)
        return 0;

        vector<int>nums;

        while(n){
            nums.push_back(n%10);
            n/=10;
        }

        vector<vector<vector<long long>>>dp(nums.size()+1, vector<vector<long long>>(s+1,vector<long long>(2,-1)));

        reverse(nums.begin(),nums.end());

        return findTotalDigit(0,s,1,nums,dp);
    }
};