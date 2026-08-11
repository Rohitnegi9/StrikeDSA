class Solution {
public:
    int countPrimes(int n) {
        // Your code here

        if(n<=2)
        return 0;

        vector<bool>visited(n,0);
        int count = 0;


        for(int i=2;i<n;i++){
            if(!visited[i]){
                count++;
                for(long long j= 1LL*i*i;j<n;j+=i){
                    visited[j] = 1;
                }
            }
        }

        return count;
    }
};