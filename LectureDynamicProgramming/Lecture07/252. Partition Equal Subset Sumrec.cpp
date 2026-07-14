class Solution {
public:
    bool findSubset(int n, int target, vector<int>&arr){
    if(target==0)
    return 1;

    if(n==0 || target<0)
    return 0;


    return findSubset(n-1,target,arr)+findSubset(n-1,target-arr[n-1],arr);
}


bool canPartition(vector<int>& arr) {
    int target = 0, n = arr.size();

    for(int i=0;i<n;i++){
        target+=arr[i];
    }


    if(target%2)
    return 0;


    return findSubset(n,target/2,arr);
}
};