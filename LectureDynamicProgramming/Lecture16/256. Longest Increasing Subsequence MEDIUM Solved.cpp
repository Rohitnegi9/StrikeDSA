int lengthOfLIS(vector<int>& nums) {
    
    int n = nums.size();
    vector<int>answer(1,nums[0]);

    for(int i=1;i<n;i++){

        int index = lower_bound(answer.begin(),answer.end(),nums[i]) - answer.begin();

        if(index==answer.size()){
            answer.push_back(nums[i]);
        }
        else if(nums[i]<answer[index]){
            answer[index] = nums[i];
        }
    }

    return answer.size();
}

// Binary search
