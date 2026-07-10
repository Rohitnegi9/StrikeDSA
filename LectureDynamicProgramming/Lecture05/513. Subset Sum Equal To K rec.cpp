class Solution {
public:
    
    bool findSubset(int index, int sum, vector<int>& arr){
        
        if(sum==0)
        return 1;

        if(sum<0 || index<0)
        return 0;

        // not pick or pick
       return findSubset(index-1,sum,arr) || findSubset(index-1,sum-arr[index],arr);
    }


    bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Your code here

        return findSubset(n-1,k,arr);
    }
};