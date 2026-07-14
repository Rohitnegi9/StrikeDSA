class Solution {
public:
    
    int findSubset(int index, int target, vector<int>& arr){
        
        if(index<0){
           return target==0;
        }

        return findSubset(index-1,target,arr)+findSubset(index-1,target-arr[index],arr);
    }
  

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here

        int n = arr.size();
        return findSubset(n-1,target,arr);
    }
};