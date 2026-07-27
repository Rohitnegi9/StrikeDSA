class Solution {
public:
    
    bool matched(int m, int n, string &s, string &p){
        
        if(m==0 && n==0)
        return 1;

        if(n==0 && m)
        return 0;

        // m == 0, n exist karta hai, second string: saare ke saare element aga * answrer, nahi toh zero

        if(m==0){
            for(int k=0;k<n;k++)
            if(p[k]!='*')
            return 0;

            return 1;
        }



        if(p[n-1]=='?')
        return matched(m-1,n-1,s,p);
        else if(p[n-1]=='*'){
            return matched(m,n-1,s,p) || matched(m-1,n,s,p);
        }
        else if(s[m-1]==p[n-1])
        return matched(m-1,n-1,s,p);
        else
        return 0;
    }

    // rohit  fdlsakfd

    bool isMatch(string s, string p) {
        // Your code here

        int m = s.size(), n = p.size();

        return matched(m,n,s,p);
    }
};