class Solution {
public:
    

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Your code here

        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size();
        vector<int>LIS(n,1);
        int maxLen = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]){
                    if(LIS[i]<1+LIS[j])
                    LIS[i] = 1+LIS[j];
                }
            }

            maxLen = max(maxLen,LIS[i]);
        }

        return maxLen;
    }
};