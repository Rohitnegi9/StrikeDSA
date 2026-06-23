class Solution {
public:
    int assignMiceHoles(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());

        int answer = 0;

        int n = mices.size();

        for(int i=0;i<n;i++){
            answer = max(answer,abs(mices[i]-holes[i]));
        }

        return answer;
    }
};