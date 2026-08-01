class Solution {
public:
    
    static bool comp(string word1, string word2){
        return word1.size()<word2.size();
    }

    int longestStrChain(vector<string>& words) {
        // Your code here
        
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>dp;
        int maxLen = 1;


        for(auto w: words){
            dp[w] = 1;
            for(int i=0;i<w.size();i++){

                string str = w.substr(0,i)+w.substr(i+1);
                
                if(dp.count(str)){
                    dp[w] = max(dp[w],1+dp[str]);
                }
            }

            maxLen = max(maxLen,dp[w]);
        }

        return maxLen;


    }
};