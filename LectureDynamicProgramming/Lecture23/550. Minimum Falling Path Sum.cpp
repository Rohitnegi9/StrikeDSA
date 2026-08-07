class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Your code here

        int n = matrix.size();
        // down, left dignol, rightDignol

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int minChoice = matrix[i+1][j];
                if(j>0) minChoice = min(minChoice, matrix[i+1][j-1]);
                if(j<n-1) minChoice = min(minChoice, matrix[i+1][j+1]);

                matrix[i][j]+=minChoice;
            }
        }

        // first row pe check karo, which is the minimym value
        int result = INT_MAX;
        for(int j=0;j<n;j++){
            result = min(result, matrix[0][j]);
        }

        return result;
    }
};