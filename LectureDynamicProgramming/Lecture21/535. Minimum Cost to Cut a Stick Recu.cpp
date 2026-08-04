class Solution {
public:

    // [1,2,4,5,6]
    //. 0 1 2 3 4

    // start = 0, end = 4 , rodStart = 0, rodEnd = 9
    // k = 2 , cuts[k] = 4

    // leftside = 0,4 (0,1)             // rightSide = 4,9 (3,4)
    
    int findMinCost(int start, int end, int rodStart, int rodEnd, vector<int>&cuts){
        
        if(start>end){
            return 0;
        }

        // try all the cuts
        int result = INT_MAX;
        for(int k=start;k<=end;k++){
           // leftSide, rightSide
           int answer = rodEnd-rodStart + findMinCost(start,k-1,rodStart,cuts[k],cuts)+findMinCost(k+1,end,cuts[k],rodEnd,cuts);

           result = min(answer,result);
        }

        return result;
    }

    int minCost(int n, vector<int>& cuts) {
        // Your code here

        sort(cuts.begin(),cuts.end());

        return findMinCost(0,cuts.size()-1, 0,n, cuts);
    }
};