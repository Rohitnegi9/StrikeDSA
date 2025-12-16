// Link: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

bool isSorted(int arr[], int n) {
    // Code Here
    
    // previous element > current element, return false
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    
    return true;
}