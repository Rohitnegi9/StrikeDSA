int minStep(int m, int n, string &word1, string &word2){
    
    if(m==0)
    return n;

    if(n==0)
    return m;



    if(word1[m-1]==word2[n-1]){
        return minStep(m-1,n-1,word1,word2);
    }
    else{
        int deleted = 1+ minStep(m-1,n,word1,word2);
        int inserted = 1+minStep(m,n-1,word1,word2);
        int replaced = 1+ minStep(m-1,n-1,word1,word2);

        return min(deleted,min(inserted,replaced));
    }
}


int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    return minStep(m,n,word1,word2);
}