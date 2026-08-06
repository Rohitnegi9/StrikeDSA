class Solution {
public:
    bool isScrambleString(string s1, string s2){
    
    if(s1==s2)
    return true;

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

        bool noSwap = isScrambleString(s1.substr(0,i) , s2.substr(0,i)) && isScrambleString(s1.substr(i), s2.substr(i));

        if(noSwap)
        return true;

        bool swap = isScrambleString(s1.substr(0,i),s2.substr(n-i)) && isScrambleString(s1.substr(i),s2.substr(0,n-i));

        if(swap)
        return true;
    }

    return false;

    }


    bool isScramble(string s1, string s2) {
        
        return isScrambleString(s1,s2);
    }
};