class Solution {
public:
    int minCoins(int n) {
        // code here
        int count = 0;
        int arr[4] = {10,5,2,1};
        int i = 0;

        while(n){
            count+=(n/arr[i]);
            n%=arr[i];
            i++;
        }

        return count;
    }
};