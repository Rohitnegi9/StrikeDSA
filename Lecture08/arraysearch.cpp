// Link: https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

// User function Template for C

int search(int arr[], int n, int x) {
    // Code here
    // linear search
    
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    
    return -1;
}