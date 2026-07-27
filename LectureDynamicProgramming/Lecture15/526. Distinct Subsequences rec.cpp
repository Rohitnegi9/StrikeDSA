class Solution {
public:
    
    int totalSub(int m, int n, string &s, string &t){
        
        if(n==0)
        return 1;

        if(m==0)
        return 0;



        if(s[m-1]==t[n-1]){
            return totalSub(m-1,n-1,s,t)+totalSub(m-1,n,s,t);
        }
        else{
            return totalSub(m-1,n,s,t);
        }
    }

    int numDistinct(string s, string t) {
        // Your code here
        int m = s.size(), n = t.size();

        return totalSub(m,n,s,t);
    }
};