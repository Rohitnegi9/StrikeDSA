class Solution {
public:
    
    static bool comp(string word1, string word2){
        return word1.size()<word2.size();
    }

    bool isPredecessor( string word1, string word2){
        if(word1.size()+1!=word2.size())
        return 0;

        int i = word1.size() , j= word2.size();

        while(i&&j){
            if(word1[i-1]==word2[j-1])
            i--,j--;
            else
            j--;
        }

        return i==0;
    }

    int longestStrChain(vector<string>& words) {
        // Your code here
        // size ke basis pe sort karo
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>LCS(n,1);
        int maxLen = 1;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(isPredecessor(words[j],words[i])){
                    LCS[i] = max(LCS[i],1+LCS[j]);
                }
            }

            maxLen = max(maxLen, LCS[i]);

        }

        return maxLen;
    }
};