int minChar(string &s) {
    // Your code here
    
	string temp = s;
	reverse(temp.begin(),temp.end());
	int n = s.size();

	s+=temp;

	int prefix = 0, suffix = 1;
	vector<int>LPS(s.size(),0);

	while(suffix<s.size()){

		if(s[prefix]==s[suffix]){
			LPS[suffix] = prefix+1;
			prefix++, suffix++;
		}
		else{
			if(prefix==0){
				suffix++;
			}
			else{
				prefix = LPS[prefix-1];
			}
		}
	}


	if(n-LPS[s.size()-1]>=0){
		return n-LPS[s.size()-1];
	}

	return 0;
}

// More Optimize Approach without create extra string temp
class Solution {
  public:
  void getlps(string &s,vector<int>&lps,int &n){
      int prefix=0,suffix=1;
      while(suffix<n){
          if(s[prefix]==s[suffix]){
              lps[suffix]=prefix+1;
              suffix++,prefix++;
          }
          else{
              if(prefix==0) suffix++;
              else prefix=lps[prefix-1];
          }
      }
  }
    int minChar(string &s) {
        int n=s.size(),prefix=0,suffix=n-1;
        vector<int>lps(n,0);
        getlps(s,lps,n);
        while(suffix>=0){
            if(s[prefix]==s[suffix]){
                suffix--,prefix++;
            }
            else{
                if(prefix==0) suffix--;
                else prefix=lps[prefix-1];
            }
        }
        return n-prefix;
    }
};
