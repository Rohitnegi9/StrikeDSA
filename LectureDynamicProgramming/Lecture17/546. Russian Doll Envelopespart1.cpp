class Solution {
public:
    
    static bool comp(vector<int>first, vector<int>second){
        if(first[0]==second[0]){
            return first[1]>second[1];
        }

        return first[0]<second[0];
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Your code here

        // ascending order, first value, descending order second value-->


        sort(envelopes.begin(),envelopes.end(),comp);
        int n = envelopes.size();
        vector<int>temp(1,envelopes[0][1]);

        for(int i=1;i<n;i++){

            int index = lower_bound(temp.begin(),temp.end(), envelopes[i][1])-temp.begin();

            if(index==temp.size()){
                temp.push_back(envelopes[i][1]);
            }
            else{
                temp[index] = envelopes[i][1];
            }
        }

        return temp.size();

    }
};