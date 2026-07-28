int maxSumIncreasingSubsequence(vector<int> &arr) {
    
    int n = arr.size();
    vector<int>MSIS = arr;
    int result = arr[0];


    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                MSIS[i] = max(MSIS[i], arr[i]+MSIS[j]);
            }
        }

        result = max(MSIS[i],result);
    }


    return result;
}