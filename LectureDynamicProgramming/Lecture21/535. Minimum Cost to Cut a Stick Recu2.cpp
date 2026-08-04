class Solution {
public:

    // [0,1,2,4,5,6,9]
    //.0  1 2 3 4 5 6

    // start = 0, end = 4 , rodStart = 0, rodEnd = 9
    // k = 2 , cuts[k] = 4

    // leftside = 0,4 (0,1)             // rightSide = 4,9 (3,4)
    
    int findMinCost(int start, int end, vector<int>&cuts){
        
        if(start+1 == end){
            return 0;
        }

        // try all the cuts
        int result = INT_MAX;
        for(int k=start+1;k<end;k++){
           // leftSide, rightSide
           int answer = cuts[end]-cuts[start]+ findMinCost(start,k,cuts)+findMinCost(k,end,cuts);
           result = min(answer,result);
        }

        return result;
    }

    int minCost(int n, vector<int>& cuts) {
        // Your code here
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        return findMinCost(0,cuts.size()-1,cuts);
    }
};