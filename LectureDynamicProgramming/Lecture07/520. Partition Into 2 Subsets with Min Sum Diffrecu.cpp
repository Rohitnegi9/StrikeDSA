class Solution {
public:
   
   int findMinDiff(int n, int sum1, int sum2, vector<int>&arr){
        
        if(n==0){
            return abs(sum1-sum2);
        }

       return min(findMinDiff(n-1,sum1+arr[n-1],sum2,arr), findMinDiff(n-1,sum1,sum2+arr[n-1],arr));
   }


    int minDifference(vector<int>& arr) {
        // Your code here
        int sum1 = 0, sum2 = 0, n = arr.size();

        return findMinDiff(n,sum1,sum2,arr);
    }
};