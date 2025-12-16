// Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks#approach-3-using-xor-operation-on-time-and-o1-space


// first solution
int missingNum(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        for(int i=1;i<=(size+1);i++){
        
        bool found = false;
        // array ko traverse karna, for particular value i
        for(int j=0;j<size;j++){
            if(arr[j]==i){
               found = true;
               break;
            }
        }
        
        
        if(found==false){
            return i;
        }
    }
    }


// another solution
    
int missingNum(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        int sum = 0;
        long long n = size+1;
        
        for(int i=0;i<size;i++){
            sum+=arr[i];
        }
        
        //  sum = 11
        
        //  sum of first n natural number
        n = n*(n+1)/2;
        // n = 15
        
        return n-sum;
        
        
    }


    // Another solution

 class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int size = arr.size();
        int ans = 0;
        
        //  xor of whole array
        for(int i=0;i<size;i++){
            ans = ans^arr[i];
        }
        
        // ans = xor of array
        
        // xor karunga to size+1
        int x = 0;
        for(int i=1;i<=size+1;i++){
           x = x^1;
        }
        
        return ans^x;
    }
};   