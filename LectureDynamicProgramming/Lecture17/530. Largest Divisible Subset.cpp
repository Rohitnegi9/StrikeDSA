class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Your code here

        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>LDS(n,1);
        vector<int>Parent(n,-1);

        int maxLen = 1, index = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(LDS[i]<1+LDS[j])
                    {
                        LDS[i] = 1+LDS[j];
                        Parent[i] = j;
                    }
                }
            }
            if(maxLen < LDS[i]){
            maxLen = LDS[i];
            index = i;
            }
    
        }

    vector<int>answer;
    while(index!=-1){
        answer.push_back(nums[index]);
        index = Parent[index];
    }

    reverse(answer.begin(),answer.end());

    return answer;
    }
};