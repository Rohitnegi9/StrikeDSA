class Solution {
public:
    
    int minEnergy(int index, vector<int>& heights, int k){
        if(index==0)
        return 0;


        int result = INT_MAX;

        for(int i=1; i<=k && i<=index; i++){
            result = min(result, abs(heights[index]-heights[index-i])+ minEnergy(index-i,heights,k));
        }

        return result;
    }


    int minimizeEnergy(vector<int>& heights, int k) {
        // Your code here

        int n = heights.size();

        return minEnergy(n-1,heights,k);
    }
};