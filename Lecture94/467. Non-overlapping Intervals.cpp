bool comp(vector<int>&a, vector<int>&b){
    return a[1] <= b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // code here
        // sort them on the bases of their end time:

        sort(intervals.begin(),intervals.end(),comp);
        
        int lastEndTime = -50000, totalRemoveInterval = 0, n = intervals.size();

        for(int i=0;i<n;i++){
            if(lastEndTime<=intervals[i][0]){
                lastEndTime = intervals[i][1];
            }
            else{
                totalRemoveInterval++;
            }
        }

        return totalRemoveInterval;
        

    }
};