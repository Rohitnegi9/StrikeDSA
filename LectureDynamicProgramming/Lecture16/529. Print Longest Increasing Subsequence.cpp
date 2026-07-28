class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>LIS(n,1);
        vector<int>Parent(n,-1);
        int result = 1, index = 0; 
        // result: Long Increasing subsequnce length
        // index: Index of that particular element whos LIS is largest


        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && (LIS[i]<1+LIS[j])){
                    LIS[i] = 1+LIS[j];
                    Parent[i] = j;
                }
            }

            if(result<LIS[i]){
                result = LIS[i];
                index = i;
            }
        }


        vector<int>answer;
        while(index!=-1){
            answer.push_back(arr[index]);
            index = Parent[index];
        }

        reverse(answer.begin(),answer.end());

        return answer;


    }
};