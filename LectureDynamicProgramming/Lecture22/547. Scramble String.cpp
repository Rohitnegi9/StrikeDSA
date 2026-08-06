class Solution {
public:
    // 
    bool isScrambleString(string s1, string s2,unordered_map<string,bool>&dp){
    
    if(s1==s2)
    return true;

    string key = s1+s2;

    if(dp.find(key)!=dp.end())
    return dp[key];

    int n = s1.size();
    vector<int>freq(26,0);

    for(int i=0;i<n;i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }

    for(int count: freq){
        if(count)
        return 0;
    }
    // 

    // split string at each all length

    for(int i=1;i<n;i++){

        bool noSwap = isScrambleString(s1.substr(0,i) , s2.substr(0,i),dp) && isScrambleString(s1.substr(i), s2.substr(i),dp);
         
        
        if(noSwap)
        return dp[key] = true;

        bool swap = isScrambleString(s1.substr(0,i),s2.substr(n-i),dp) && isScrambleString(s1.substr(i),s2.substr(0,n-i),dp);

        if(swap)
        return dp[key]= true;
    }

    return dp[key] = false;

    }
 
    bool isScramble(string s1, string s2) {
        // Your code here

         int n = s1.size();

        unordered_map<string,bool>dp;

        return isScrambleString(s1,s2,dp);
    }
};